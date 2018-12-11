//MOTOTRS
#include <Servo.h>
Servo myservo;
int MotorPin = 11; //Digital port D11
int sped = 1505;
int incomingByte = 0;

//ULTRASONIC
int echoPin = 2;//Digital port D2
int trigPin = 3;//Digital port D3
int delay_us = 10;
int dist = 0;
long distance_mm = 0;
long duration_us = 0;
const long intervalSonic = 2000;//How often to check ultrosonis
unsigned long previousMillisSonic = 0;


//FAN
int FanPin = 7;//Digital port D7
//LIGHT controll
int LEDPin = 8;//Digital port D8
boolean state;

//TIMER
unsigned long previousMillisTimer = 0;
const long interval = 3000;

void setup() {
  // MOTORS setup
  Serial.begin(9600);
  myservo.attach(MotorPin);
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
  unsigned long currentMillis = millis();//real time for timers

  //Communication
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.parseInt();
    Serial.println(incomingByte);
    //myservo.writeMicroseconds(sped + incomingByte);
  }


// Once in a !intervalSonic! read data from ultrasonic, when no sensor control wia Serial Monitor(-100 to 100)
  if (currentMillis - previousMillisSonic >= intervalSonic) {
    // save the last time you checked ultrosonic
    previousMillisSonic = currentMillis;
    //Getting distance from ultro in santimeters
    dist = ultro();
    //Adjusting the ceiling
    if (dist > 10) {
      myservo.writeMicroseconds(sped + 80);
    }
    else if (dist < 7) {
      myservo.writeMicroseconds(sped - 80);
      if (dist <= 1) {
        Serial.println("No Ultra");
        myservo.writeMicroseconds(sped + incomingByte);
      }
    }
    else {
      myservo.writeMicroseconds(sped);
    }
  }


  if (currentMillis - previousMillisTimer >= interval) {
    // save the last time you blinked the LED
    previousMillisTimer = currentMillis;

    if (state == HIGH) {
      state = LOW;
    }
    else {
      state = HIGH;
    }
  }

  digitalWrite(7, HIGH);   // turn the LED on and off (HIGH and LOW)
  digitalWrite(8, HIGH);

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

