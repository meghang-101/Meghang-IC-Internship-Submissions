#####///// SERVER CODE /////#####
import RPi.GPIO as GPIO
import socket
import numpy as np
import encodings

HOST = socket.gethostname() #Mention IP address of Raspberry Pi
PORT = 1024

def my_server():
    print("Connecting to Server...")
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((HOST, PORT))
    s.listen(5)
    conn, addr = s.accept()
    print(f"Connecttion to {addr} has been established.")
    conn.send(bytes("Sensor Data from Raspberry Pi", "utf-8"))
    conn.close()

my_server()
