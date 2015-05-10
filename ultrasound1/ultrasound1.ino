int echoPin     = 12;
int triggerPin  = 11;

void setup() {
  Serial.begin(9600);
  
  pinMode(echoPin,    INPUT);
  pinMode(triggerPin, OUTPUT);
}

void loop() {
  talk();
  int distance = listenEcho();
  report(distance);
  
  delay(80);
}

void talk(){
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
}

long listenEcho(){
  long  duration = pulseIn(echoPin, HIGH);
  return (int) (duration / 2) / 29.1;
}

void report(long distance){
  if (distance > 400 || distance <= 0) {
    Serial.println("Out of range");
    Serial.print("Distance = ");
    Serial.println(distance);
    distance = 400;
  } else {
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
  }
}

