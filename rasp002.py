#####///// CLIENT CODE /////#####
import socket

HOST = socket.gethostname() #Mention IP address of Data Parsing device
PORT = 1024

new_info = ''

def my_client():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(HOST, PORT)
    msg = s.recv(1024)

    if len(msg) <= 0:
        break
    new_info += msg.decode("utf-8")
    print(new_info)

my_client()
