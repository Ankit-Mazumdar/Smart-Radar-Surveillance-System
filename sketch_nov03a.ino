// ✅ Final Arduino Radar Code (Timestamp, Angle, Distance, Direction, Speed, Threat)
#include <Servo.h>

Servo myServo;

const int trigPin = 10;
const int echoPin = 11;
const int servoPin = 9;
const int redLed = 7;
const int greenLed = 8;
const int buzzer = 6;

long duration;
int distance;
int prevDistance = 999;
int prevAngle = 0;
unsigned long prevTime = 0;

// Track intruder logging state
bool intruderActive = false;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(greenLed, HIGH);
  noTone(buzzer);
}

void loop() {

  // Sweep LEFT ➝ RIGHT
  for (int angle = 15; angle <= 165; angle += 2) {
    scan(angle);
  }

  // Sweep RIGHT ➝ LEFT
  for (int angle = 165; angle >= 15; angle -= 2) {
    scan(angle);
  }
}

void scan(int angle) {
  myServo.write(angle);
  delay(30);

  distance = getFilteredDistance();

  float speed = calculateSpeed(angle, distance);
  String direction = getDirection(angle);
  String threat = getThreatLevel(distance);

  sendData(angle, distance, speed, direction, threat);

  prevDistance = distance;
  prevAngle = angle;
  prevTime = millis();
}

// ✅ Median filter (depth filter)
int getFilteredDistance() {
  int d1 = measureDistance();
  int d2 = measureDistance();
  int d3 = measureDistance();

  return max(min(d1, max(d2, d3)), min(d2, max(d1, d3)));
}

// ✅ Ultrasonic measurement
int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) return 999;

  int dist = (duration * 0.034) / 2;
  return (dist < 2 || dist > 400) ? 999 : dist;
}

// ✅ Speed calculation (cm/s)
float calculateSpeed(int currentAngle, int currentDistance) {
  if (prevDistance >= 999 || currentDistance >= 999) return 0.0;

  float timeDiff = (millis() - prevTime) / 1000.0;
  if (timeDiff <= 0) return 0.0;

  float speed = abs(currentDistance - prevDistance) / timeDiff;
  return (speed > 200) ? 0.0 : speed;
}

// ✅ LEFT / CENTER / RIGHT zone
String getDirection(int angle) {
  if (angle < 60) return "LEFT";
  if (angle < 120) return "CENTER";
  return "RIGHT";
}

// ✅ Threat level
String getThreatLevel(int dist) {
  if (dist < 15) return "DANGER";
  if (dist < 40) return "WARNING";
  return "SAFE";
}

// ----------------------------------------------

// ✅ Send full data packet to Processing (CSV format)
// Format: timestamp,angle,distance,direction,speed,threat
// void sendData(int angle, int dist, float speed, String dir, String threat) {

// unsigned long timestamp = millis(); // <-- timestamp included

//  Serial.print(timestamp);  // Serial.print(",");
//  Serial.print(angle);    //   Serial.print(",");
 // Serial.print(dist);      //  Serial.print(",");
 // Serial.print(dir);       //  Serial.print(",");
 // Serial.print(speed, 1);  //  Serial.print(",");
 // Serial.println(threat);

 // handleAlert(dist);
//}
// ----------------------------------------------------

  void sendData(int angle, int dist, float speed, String dir, String threat) {

  unsigned long timestamp = millis(); // <-- timestamp included

  Serial.print(timestamp);   Serial.print(",");
  Serial.print(angle);       Serial.print(",");
  Serial.print(dist);        Serial.print(",");
  Serial.print(dir);         Serial.print(",");
  Serial.print(speed, 1);    Serial.print(",");
  Serial.print(threat);      Serial.print(",");
  Serial.println("NA");      // ✅ 7th field placeholder (Date/Time for Processing)

  handleAlert(dist);
}


// ✅ LED and buzzer logic
void handleAlert(int dist) {
  if (dist < 15) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 2000);
  }
  else if (dist < 40) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    noTone(buzzer);
  }
  else {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    noTone(buzzer);
  }
}
