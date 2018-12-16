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
const int intervalSonic = 2000;//How often to check ultrosonis
unsigned long previousMillisSonic = 0;


//FAN
int FanPin = 7;//Digital port D7
//LIGHT controll
int LEDPin = 8;//Digital port D8
boolean LEDstate = LOW;

//LIGHT sensors
int LightSensPin1 = A1;//Analog port 15 sensor on TOP
int LightSensPin2 = A2;//Analog port 16 sensor on BOTTOM
int LightValue1 = 0;
int LightValue2 = 0;
int illuminanceMean = 15; //mapped value from 0 to 255
unsigned long previousMillisLight = 0;
const int intervalLight = 1000;

//DHT11 Sensor
int read(int pin, byte* ptemperature, byte* phumidity, byte pdata[40]);
int confirm(int pin, int us, byte level);
byte bits2byte(byte data[8]);
int sample(int pin, byte data[40]);
int parse(byte data[40], byte* ptemperature, byte* phumidity);
byte temperature = 0;
byte humidity = 0;
int DHTPin = 4;//Digital port D4
int DHTValue = 0;
unsigned long previousMillisDHT = 0;
const int intervalDHT = 1000;
int temp = 0;
int humid = 0;

//SOIL-HUMIDITY sensor
int SoilPin = A0;    // select the input pin for the Soil moisture sensor
int SoilValue = 0;  // variable to store the value coming from the sensor
unsigned long previousMillisSoil = 0;
const int intervalSoil = 1000;
int MinSoil = 300;

//Beeper
int BeeperPin = 5;//Digital port D5
boolean beeperState = LOW;
//TIMER
unsigned long previousMillisTimer = 0;
const int intervalTimer = 3000;


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

  //FAN control
  pinMode(FanPin, OUTPUT);//7
  //LIGHT controll
  pinMode(LEDPin, OUTPUT);//8

  //LightSensors
  pinMode(LightSensPin1, INPUT);
  pinMode(LightSensPin1, INPUT);

  //Siol-Moisture Sensor
  pinMode(SoilPin, INPUT);

  //Beeper
  pinMode(BeeperPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long currentMillis = millis();//real time for timers

  //Communication
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.parseInt();
    //Serial.println(incomingByte);
  }
  //PLOTTING
  Serial.print(LightValue1); Serial.print(" LightSens1, ");
  Serial.print(LightValue2); Serial.print(" LightSens2, ");
  //Serial.print(dist); Serial.print(" dist");
  Serial.print(temp); Serial.print(" *C, ");
  Serial.print(humid); Serial.print(" %");
  //Serial.print(SoilValue / 10); Serial.print(" Soil humidity ");


  //Getting readings from Light Sensors per 2sec
  if (currentMillis - previousMillisLight >= intervalLight) {
    previousMillisLight = currentMillis;    // save the last time you checked Light
    LightValue1 = analogRead(LightSensPin1);
    LightValue2 = analogRead(LightSensPin2);

    LightValue1 = map(LightValue1, 0, 1025, 0, 255);
    LightValue2 = map(LightValue2, 0, 1025, 0, 255);

    if ((LightValue1) < illuminanceMean) {//90
      digitalWrite(LEDPin, HIGH);   // turn the LED ON
    }
    else {
      digitalWrite(LEDPin, LOW);
    }
  }


  //Getting readings from DHT11 per 2sec
  if (currentMillis - previousMillisDHT >= intervalDHT) {
    previousMillisDHT = currentMillis;    // save the last time you checked DHT
    //  DHTValue = digitalRead(DHTPin);
    // read without samples.
    temperature = 0;
    humidity = 0;
    if (read(DHTPin, &temperature, &humidity, NULL)) {
      Serial.print("Syncing DHT");
      return;
    }
    temp = int(temperature);
    humid = int(humidity);
    if (humidity > 60) {
      digitalWrite(FanPin, HIGH);   // turn the FAN ON
      //Serial.println(humidity);
    }
    else {
      digitalWrite(FanPin, LOW);
    }
  }

  if (currentMillis - previousMillisSoil >= intervalSoil) {
    previousMillisSoil = currentMillis;
    SoilValue = analogRead(SoilPin);
    if (SoilValue < MinSoil) {
      if (currentMillis - previousMillisTimer >= intervalTimer) {
        previousMillisTimer = currentMillis;
        if (beeperState == LOW) {
          beeperState = HIGH;
        }
        else{
          beeperState =LOW;
        }
        digitalWrite(BeeperPin, beeperState);
      }
    }
    else {
      digitalWrite(BeeperPin, LOW);
    }
  }

  // Once in a !intervalSonic!(2sec) read data from ultrasonic, when no sensor control wia Serial Monitor(-100 to 100)
  if (currentMillis - previousMillisSonic >= intervalSonic) {    // save the last time you checked ultrosonic
    previousMillisSonic = currentMillis;    //Getting distance from ultro in santimeters
    dist = ultro();
    //Adjusting the ceiling
    if (dist > 10) {
      myservo.writeMicroseconds(sped + 80);
    }
    else if (dist < 7) {
      myservo.writeMicroseconds(sped - 80);
      if (dist <= 1) {
        //Serial.println("No Ultra");
        myservo.writeMicroseconds(sped + incomingByte);
      }
    }
    else {
      myservo.writeMicroseconds(sped);
    }
  }


  Serial.println();
}//end

//FUNCTIONS

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
  //Serial.print(distance_mm);Serial.print(" dist");
  delay(10);
  return distance_mm / 10;
}


//DHT 11
int confirm(int pin, int us, byte level) {
  // wait one more count to ensure.
  int cnt = us / 10 + 1;
  bool ok = false;
  for (int i = 0; i < cnt; i++) {
    if (digitalRead(pin) != level) {
      ok = true;
      break;
    }
    delayMicroseconds(10);
  }
  if (!ok) {
    return -1;
  }
  return 0;
}

byte bits2byte(byte data[8]) {
  byte v = 0;
  for (int i = 0; i < 8; i++) {
    v += data[i] << (7 - i);
  }
  return v;
}

int sample(int pin, byte data[40]) {
  // empty output data.
  memset(data, 0, 40);

  // notify DHT11 to start:
  //    1. PULL LOW 20ms.
  //    2. PULL HIGH 20-40us.
  //    3. SET TO INPUT.
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delay(20);
  digitalWrite(pin, HIGH);
  delayMicroseconds(30);
  pinMode(pin, INPUT);

  // DHT11 starting:
  //    1. PULL LOW 80us
  //    2. PULL HIGH 80us
  if (confirm(pin, 80, LOW)) {
    return 100;
  }
  if (confirm(pin, 80, HIGH)) {
    return 101;
  }

  // DHT11 data transmite:
  //    1. 1bit start, PULL LOW 50us
  //    2. PULL HIGH 26-28us, bit(0)
  //    3. PULL HIGH 70us, bit(1)
  for (int j = 0; j < 40; j++) {
    if (confirm(pin, 50, LOW)) {
      return 102;
    }

    // read a bit, should never call method,
    // for the method call use more than 20us,
    // so it maybe failed to detect the bit0.
    bool ok = false;
    int tick = 0;
    for (int i = 0; i < 8; i++, tick++) {
      if (digitalRead(pin) != HIGH) {
        ok = true;
        break;
      }
      delayMicroseconds(10);
    }
    if (!ok) {
      return 103;
    }
    data[j] = (tick > 3 ? 1 : 0);
  }

  // DHT11 EOF:
  //    1. PULL LOW 50us.
  if (confirm(pin, 50, LOW)) {
    return 104;
  }

  return 0;
}

int parse(byte data[40], byte * ptemperature, byte * phumidity) {
  byte humidity = bits2byte(data);
  byte humidity2 = bits2byte(data + 8);
  byte temperature = bits2byte(data + 16);
  byte temperature2 = bits2byte(data + 24);
  byte check = bits2byte(data + 32);
  byte expect = humidity + humidity2 + temperature + temperature2;
  if (check != expect) {
    return 105;
  }
  *ptemperature = temperature;
  *phumidity = humidity;
  return 0;
}

int read(int pin, byte * ptemperature, byte * phumidity, byte pdata[40]) {
  int ret = 0;

  byte data[40] = {0};
  if ((ret = sample(pin, data)) != 0) {
    return ret;
  }

  byte temperature = 0;
  byte humidity = 0;
  if ((ret = parse(data, &temperature, &humidity)) != 0) {
    return ret;
  }

  if (pdata) {
    memcpy(pdata, data, 40);
  }
  if (ptemperature) {
    *ptemperature = temperature;
  }
  if (phumidity) {
    *phumidity = humidity;
  }

  return ret;
}

// Works good.
