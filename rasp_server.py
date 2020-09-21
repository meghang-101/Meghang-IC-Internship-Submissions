import RPi.GPIO as GPIO
import socket
import numpy as np
import encodings
import time

GPIO.setmode(GPIO.BOARD)
TrigPin = 16
EchoPin = 18

GPIO.setup(TrigPin, GPIO.OUT)
GPIO.setup(EchoPin, GPIO.IN)

GPIO.output(TRIG, False)
time.sleep(2)

HOST = socket.gethostname() #Mention IP address of Raspberry Pi
PORT = 1024

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(5)
conn, addr = s.accept()
print(f"Connecttion to {addr} has been established.")

try:
    while True:
       GPIO.output(TRIG, True)
       time.sleep(0.00001)
       GPIO.output(TRIG, False)

       while GPIO.input(ECHO)==0:
          pulse_start = time.time()

       while GPIO.input(ECHO)==1:
          pulse_end = time.time()

    pulse_duration = pulse_end - pulse_start

    distance = pulse_duration * 17150
    distance = round(distance+1.15, 2)
    distance = str(distance)

    conn.send(bytes(distance, "utf-8"))
    conn.close()

except KeyboardInterrupt:
     GPIO.cleanup()
