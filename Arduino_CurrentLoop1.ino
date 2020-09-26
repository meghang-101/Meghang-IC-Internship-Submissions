#include <math.h>
#include <string.h>

#define sensorPin A1

void setup(){
  Serial.begin(11500); //sets up Serial Communication at baud rate of 11500
}

void loop() {
  double sensorValue = analogRead(sensorPin); //Reads Voltage value from Analog pin A1
  sensorValue = ((sensorValue-204.0)*100.0)/(1024.0-204.0); //204 is offset, 4mAmp is 0 units... This value id representd as PERSENTAGE

  //Conversion Factor (Depends on Sensor)
  //For UM18-2 Core Ultrasonic Sensor, the approximate range is form 20mm to 150mm. That is, the sensor range is 130mm.
  sensorValue = 20 + ((sensorValue / 100) * 130);

  Serial.print(sensorValue); //Prints value to Serial monitor
}
