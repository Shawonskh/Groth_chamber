
#include <Servo.h>

Servo myservo;


void setup() {
  // put your setup code here, to run once:
  //pinMode(11, OUTPUT);
  myservo.attach(11);
  myservo.writeMicroseconds(1500);
}

void loop() {
  // put your main code here, to run repeatedly:
  //analogWrite(11, 10);
  myservo.writeMicroseconds(3000);
  delay(2000);
  myservo.writeMicroseconds(1480);
  delay(2000);
  myservo.writeMicroseconds(1520);
  delay(2000);
  myservo.writeMicroseconds(1600);
  delay(2000);

  myservo.writeMicroseconds(1500);
  delay(3000);

}
