#include <Servo.h>

Servo myservo; 

void setup() {
  Serial.begin(115200);
  Serial.println("Servo test");
  myservo.attach(9);
  myservo.write(0);
  delay(2000);
}

void loop() {
  myservo.write(0);
  delay(2000);
  myservo.write(90);
  delay(2000);
  myservo.write(180);
  delay(2000);
  myservo.write(90);
  delay(2000);
}
