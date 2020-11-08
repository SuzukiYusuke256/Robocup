# Multi Color Blob Tracking Example
#
# This example shows off multi color blob tracking using the OpenMV Cam.

import sensor, image, time, math, pyb, ustruct
# Color Tracking Thresholds (L Min, L Max, A Min, A Max, B Min, B Max)
# The below thresholds track in general red/green things. You may wish to tune them...
yellow_thresholds = [(55, 75, -15, 5, 40, 70)] #黄色ゴールのしきい値
blue_thresholds = [(30, 45, -5, 35, -60, -30)] #青色ゴールのしきい値
mirror_cx = 150
mirror_cy = 112
# You may pass up to 16 thresholds above. However, it's not really possible to segment any
# scene with 16 thresholds before color thresholds start to overlap heavily.
led = pyb.LED(3)
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000)
sensor.set_auto_gain(False) # must be turned off for color tracking
sensor.set_auto_whitebal(False) # must be turned off for color tracking
clock = time.clock()
spi = pyb.SPI(2, pyb.SPI.SLAVE, polarity=0, phase=0)
ss = pyb.Pin('P3', pyb.Pin.IN, pull=pyb.Pin.PULL_UP)
color_set_pin = pyb.Pin('P4', pyb.Pin.IN)
angle = 0
distance = 0
# Only blobs that with more pixels than "pixel_threshold" and more area than "area_threshold" are
# returned by "find_blobs" below. Change "pixels_threshold" and "area_threshold" if you change the
# camera resolution. Don't set "merge=True" becuase that will merge blobs which we don't want here.

while(True):
    clock.tick()
    img = sensor.snapshot()
    rightx = 0
    leftx = 0
    state = 0
    x = 0
    y = 0
    area1 = 0
    count = 0
    if(color_set_pin.value() == 1): #黄色ゴールを見る
        thresholds = yellow_thresholds
    else:                           #青色ゴールを見る
        thresholds = blue_thresholds
    for blob in img.find_blobs(thresholds, pixels_threshold=200, area_threshold=200):
        img.draw_rectangle(blob.rect())
        img.draw_cross(blob.cx(), blob.cy())
        if(count == 0):
            area1 =  blob.w() * blob.h() #面積 = 横 * 縦
            x = blob.cx() - mirror_cx
            y = blob.cy() - mirror_cy
            rightx = blob.cx() + (blob.w() / 2)
            leftx = blob.cx() - (blob.w() / 2)
        else: #複数見えている時
            area2 = blob.w() * blob.h()
            x = (((x * area1) + (blob.cx() - mirror_cx) * area2)) / (area1 + area2) #面積の比率に合わせて座標を修正する
            y = (((y * area1) + (blob.cy() - mirror_cy) * area2)) / (area1 + area2)
            area1 = area1 + area2
            a = blob.cx() + (blob.w() / 2)
            b = blob.cx() - (blob.w() / 2)
            if(a > rightx):
                rightx = a
            if(b < leftx):
                leftx = b
        count += 1
    if(count != 0): #ゴールが見つかった時
        angle = math.degrees(math.atan2(y, x))
        distance = (distance * 0.7) + (math.sqrt((x * x) + (y * y)) * 0.3)
        if(angle < 1): #値を1~360にする
            angle = angle + 360
        if(rightx < (mirror_cx + 25)):
            state = 1
        elif(leftx > (mirror_cx - 25)):
            state = 2
        else:
            state = 3
    else:
        angle = 0
        distance = 0
    text = str(int(angle) + (int(distance) * 1000) + (state * 1000000))
    data = ustruct.pack("<bi%ds" % len(text), 85, len(text), text) # 85 is a sync char.
    while(ss.value()): pass
    try:
        #print(text)
        #print("angle:", int(angle), "distance:", int(distance), "state:", state)
        spi.send(data, timeout=1000)
    except OSError as err:
       pass # Don't care about errors - so pass.
    while(not ss.value()): pass
    #print(clock.fps())
