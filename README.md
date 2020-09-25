# SERVER COMMUNICATION
Interfacing Arduino Uno WiFi and Raspberry Pi to a Web Server

## INTERFACING ARDUINO UNO TO A PHP SERVER
The [Arduino001.ino](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/ServerCommunication/Arduino001.ino) has the source code for connecting an Arduino uno Wifi to a Web Server. If Arduino Uno Wifi is not available then we can connect an Arduino Shield on top of the Arduino Uno. The web server in this example is a PHP Server. The source code for the PHP Server is [post.php](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/ServerCommunication/post.php).

## INTERFACING RASPBERRY PI TO A WEB SERVER 
In this example, we use a library known as Socket.
### Server Setup [rasp001.py](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/ServerCommunication/rasp001.py)
```python
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
```

### Host/Client Setup [rasp002.py](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/ServerCommunication/rasp002.py)
```python
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
```
In the next example, the Raspberry Pi sends distance data to the same web server [rasp002.py](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/ServerCommunication/rasp002.py). The code for the new example as a server is [rasp_server.py](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/ServerCommunication/rasp_server.py)

We can even consider node.js as a viable option for our server client and host communication. The file [app.js](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/ServerCommunication/app.js) has the node file source code example.

Use this command in the command prompt to run the file.

```bash
cd ~/Meghang-IC-Internship-Submissions
node app.js COM16  //instead of COM16 use the Serial port to which your Arduino is connected.
```
Run the Serial Monitor in the Arduino IDE and you will observe data being logged into the server.
