#define trigP1 11
#define echoP1 10
#define trigP2 9
#define echoP2 6
#define trigP3 5
#define echoP3 3

float duration1;
float distance1;
float duration2;
float distance2;
float duration3;
float distance3;

void setup() {
  Serial.begin(9600);

  pinMode(trigP1, OUTPUT);
  pinMode(echoP1, INPUT);
  pinMode(trigP2, OUTPUT);
  pinMode(echoP2, INPUT);
  pinMode(trigP3, OUTPUT);
  pinMode(echoP3, INPUT);

  Serial.println("CLEARDATA");
  Serial.println("LABEL,Current time,Sensor1(cm),Sensor2(cm),Sensor3(cm)");

}

void loop() {
  digitalWrite(trigP1, LOW); 
  digitalWrite(trigP2, LOW);
  digitalWrite(trigP3, LOW);

  delayMicroseconds(2);

  digitalWrite(trigP1, HIGH);  
  digitalWrite(trigP2, HIGH);
  digitalWrite(trigP3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigP1, LOW); 
  digitalWrite(trigP2, LOW);
  digitalWrite(trigP3, LOW);

  duration1 = pulseIn(echoP1, HIGH);
  duration2 = pulseIn(echoP2, HIGH);
  duration3 = pulseIn(echoP3, HIGH);

  distance1 = duration1 * 0.034 / 2;
  distance2 = duration2 * 0.034 / 2;
  distance3 = duration3 * 0.034 / 2;

  Serial.print("DATA,TIME,");
  Serial.print(distance1);
  Serial.print(",");
  Serial.print(distance2);
  Serial.print(",");
  Serial.println(distance3);
  delay(1000);
}
