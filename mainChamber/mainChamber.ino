//MOTOTRS
#include <Servo.h>
Servo myservo;
int sped = 1510;
int incomingByte = 0;

//ULTRASONIC
int echoPin = 2;
int trigPin = 3;
int delay_us = 10;
int dist = 0;
long distance_mm = 0;
long duration_us = 0;

//FAN
int FanPin = 7;//Digital port D7
//LIGHT controll
int LEDPin = 8;//Digital port D8
boolean state;

//TIMER
unsigned long previousMillis = 0;
const long interval = 3000;

void setup() {
  // MOTORS setup
  Serial.begin(9600);
  myservo.attach(11);
  myservo.writeMicroseconds(1510);

  //ULTRASONIC setup
  // Datasheet for Ultrasonic Ranging Module HC - SR04
  // https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  //FAN controll
  pinMode(FanPin, OUTPUT);//7
  //LIGHT controll
  pinMode(LEDPin, OUTPUT);//8

}

void loop() {
  // put your main code here, to run repeatedly:
  //analogWrite(11, 10);
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.parseInt();
    Serial.println(incomingByte);
    myservo.writeMicroseconds(sped + incomingByte);
  }


  //Getting distance from ultro in santimeters
  dist = ultro();
  //Adjusting the ceiling
  if (ultro() > 10) {
    myservo.writeMicroseconds(sped + 80);
  }
  else if (ultro() < 7) {
    myservo.writeMicroseconds(sped - 80);
  }
  else {
    myservo.writeMicroseconds(sped);
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    if (state == HIGH) {
      state = LOW;
    }
    else {
      state = HIGH;
    }
  }

  digitalWrite(7, state);   // turn the LED on and off (HIGH and LOW)
  digitalWrite(8, state);

}//end





int ultro() {
  // To generate the ultrasound we need to
  // set the trigPin to HIGH state for correct ammount of µs.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(delay_us);
  digitalWrite(trigPin, LOW);

  // Read the pulse HIGH state on echo pin
  // the length of the pulse in microseconds
  duration_us = pulseIn(echoPin, HIGH);
  distance_mm = duration_us * 340 / 2 / 1000; //(high level time×velocity of sound(340M/S) / 2
  Serial.println(distance_mm);
  delay(10);
  return distance_mm / 10;
}

