int LightSensPin1 = A1;//Analog port 15 sensor on TOP
int LightSensPin2 = A2;//Analog port 16 sensor on BOTTOM
int sensorValue1 = 0; // variable to store the value coming from the sensor
int sensorValue2 = 0;
int interval = 500;
long int starttime = 0;
unsigned long mytime;

void setup() {
  Serial.begin(9600);
  //LightSensors
  pinMode(LightSensPin1, INPUT);
  pinMode(LightSensPin1, INPUT);
}

void loop() {
  mytime = millis();
  sensorValue1 = analogRead(LightSensPin1);
  sensorValue2 = analogRead(LightSensPin2);

  if (mytime - starttime >= interval) {
    starttime = mytime;

    if (sensorValue1+sensorValue2 > 30) {
      Serial.println("Light comes");
    }
    else {
      Serial.println("No light");
    }
    Serial.println(sensorValue1);
    Serial.println(sensorValue2);
  }
}
