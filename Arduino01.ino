#define trigPin1 11
#define echoPin1 12
#define trigPin2 9
#define echoPin2 6
#define trigPin3 5
#define echoPin3 3

long duration1;
long duration2;
long duration3;

long distance1;
long distance2;
long distance3;

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  digitalWrite(trigPin3, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin1, HIGH);
  digitalWrite(trigPin2, HIGH);
  digitalWrite(trigPin3, HIGH);

  duration1 = pulseIn(echoPin1, HIGH);
  duration2 = pulseIn(echoPin2, HIGH);
  duration3 = pulseIn(echoPin3, HIGH);

  distance1 = duration1 * 0.034 / 2;
  distance2 = duration2 * 0.034 / 2;
  distance3 = duration3 * 0.034 / 2;

  Serial.print(distance1);
  Serial.print("cm, ");
  Serial.print(distance2);
  Serial.print("cm, ");
  Serial.print(distance3);
  Serial.println(" ");
}
