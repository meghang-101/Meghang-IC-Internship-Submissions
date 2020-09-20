import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BOARD)

TRIG1 = 11
ECHO1 = 12

TRIG2 = 31
ECHO2 = 32

TRIG3 = 33
ECHO3 = 35

GPIO.setup(TRIG1, GPIO.OUT)
GPIO.setup(TRIG2, GPIO.OUT)
GPIO.setup(TRIG3, GPIO.OUT)

GPIO.output(TRIG1, False)
GPIO.output(TRIG2, False)
GPIO.output(TRIG3, False)

time.sleep(2)

try:
    while True:
        GPIO.output(TRIG1, True)
        GPIO.output(TRIG2, True)
        GPIO.output(TRIG3, True)
        time.sleep(0.00001)
        GPIO.output(TRIG1, False)
        GPIO.output(TRIG2, False)
        GPIO.output(TRIG3, False)

        while GPIO.input(ECHO1)==0:
            pulse_start1 = time.time()
        while GPIO.input(ECHO2)==0:
            pulse_start2 = time.time()
        while GPIO.input(ECHO3)==0:
            pulse_start3 = time.time()

        while GPIO.input(ECHO1)==1:
            pulse_end1 = time.time()
        while GPIO.input(ECHO2)==1:
            pulse_end2 = time.time()
        while GPIO.input(ECHO3)==1:
            pulse_end3 = time.time()

        pulse_duration1 = pulse_end1 - pulse_start1
        pulse_duration2 = pulse_end2 - pulse_start2
        pulse_duration3 = pulse_end3 - pulse_start3

        distance1 = pulse_duration1 * 17150
        distance2 = pulse_duration2 * 17150
        distance3 = pulse_duration3 * 17150

        distance1 = round(distance1+1.15, 2)
        distance2 = round(distance2+1.15, 2)
        distance3 = round(distance3+1.15, 2)

        print("distance1 = ", distance1, " , distance2 = ", distance2, " , distance3 = ", distance3)

except KeyboardInterrupt:
    GPIO.cleanup()
