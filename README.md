# UM-18 ULTRASONIC SENSOR

## I/O INFORMATION
The input is a M12, 5-Pin, A-coded plug

![](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/UM18_Sensor/input1.PNG)

![](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/UM18_Sensor/input2.PNG)

## ANALOG OUTPUT
### CURRENT LOOP METHOD
![](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/UM18_Sensor/outputArduino1.PNG)

The Arduino source code is [Arduino_CurrentLoop1.ino](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/UM18_Sensor/Arduino_CurrentLoop1.ino). The Current value of the sensor ranges between 4mA-20mA. The Current loop method converts this value of current to its proportional value of Voltage so that the Arduino's Analog Input pins can calculate the exact value. This value is then converted to its respective sensor Distance value.

### VOLTAGE METHOD
![](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/UM18_Sensor/outputArduino2.PNG)

The Arduino code is [Arduino_VoltageMethod.ino](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/UM18_Sensor/Arduino_VoltageMethod.ino), and the proteus file is [VoltageMethod.pdsprj](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/UM18_Sensor/VoltageMethod.pdsprj). The voltage that the analog output pin delivers is between 0V to 10V. This value is feeded into a voltage divider and then to the Arduino analog pins. This value is then converted to its respective sensor Distance value.

### CONNECT+ COMMUNICATION
This is the original way of extracting a distance value out of this sensor. Connect+ is a Communication method which is a standard protocol enabled by the Pin-5 of M12 connector. The connect+ protocol requires an adapter and this system is called the "Connecter+Adapter" Communication protocol.

![](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/UM18_Sensor/LAC01.PNG)

The Adapter is connected like this

![](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/UM18_Sensor/LAC02.PNG)

The LAC-2 Adapter comes with a standard software that enables Visualization of the data send by the Sensor. The software looks like this.

![](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/UM18_Sensor/LAC03.PNG)

For more reference, visit [LinkControlSoftware](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/UM18_Sensor/LinkControlSoftware.pdf).
