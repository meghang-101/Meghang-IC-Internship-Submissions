#include<SoftwareSerial.h>
#include<string.h>
SoftwareSerial SensorOne(19, 18);
SoftwareSerial SensorTwo(17, 16);
SoftwareSerial SensorThree(15, 14);

void setup() {
  Serial.begin(11500);
  Serial.println("SensorDistance1, SensorDistance2, SensorDistance3");
}

void loop() {
  while (SensorOne.available()) {
    char inByteOne = SensorOne.read();
    break;
  }

  while (SensorTwo.available()) {
    char inByteTwo = SensorTwo.read();
    break;
  }

  while (SensorThree.available()) {
    char inByteThree = SensorThree.read();
    break;
  }

  // CONVERTION OF inByteOne, inByteTwo, inByteThree happens here
  String distance1 = inByteOne;
  String distance2 = inByteTwo;
  String distance3 = inByteThree;

  String final = distance1 + ", " + distance2 + ", " + distance3;
  Serial.println(final);
}
