#include <math.h>
#include <string.h>

#define sensorPin A1

void setup() {
  Serial.begin(11500);
}

void loop() {
  double sensorValue = analogRead(A0); //Reads Voltage value from Analog pin A1
  sensorValue = sensorValue * ((5.0 * 100.0) / 1023.0); //This value is represented as PERSENTAGE
  
  //Conversion Factor (Depends on Sensor)
  //For UM18-2 Core Ultrasonic Sensor, the approximate range is form 20mm to 150mm. That is, the sensor range is 130mm.
  sensorValue = 20 + ((sensorValue / 100) * 130);

  Serial.print(sensorValue); //Prints value to Serial monitor
}
