# ARDUINO ASSEMBLY AND EXCEL LOGGING
The following instructions will guide you to connect the 3 ultrasonic sensors to Arduino and post the Data from the sensors to an excel sheet.

# CURCUIT DIAGRAM
The following file [protues_circuit_schematic](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/ESP8266_server/assembly01.pdsprj) is the proteus file for the assembly.

![](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/ESP8266_server/assemblypic.PNG)

The following is the code for the Arduino [Arduino_Code](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/ESP8266_server/final.ino). Upload this code to the Arduino Mega board.

# EXCEL LOGGING
Download the following Software [PLX-DAQ](https://plx-daq.software.informer.com/download/) and Install it. Once the software is installed, A folder will be added to the user's desktop. Inside that folder are 2 files- Excel Sheet, Help.

After uploading the source code to arduino, Open the Serial Monitor at a baud rate of 9600ms.

Open the Excel Sheet. Enable all permissions and press "OK". A setup will be prompted. 

![](https://github.com/meghang-101/Meghang-IC-Internship-Submissions/blob/ESP8266_server/excelpic.PNG)

Select the proper PORT CONNECTION, BAUD RATE and select the DOWNLOAD DATA and then click CONNECT. Data will log in the excel sheet.
