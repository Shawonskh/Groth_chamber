int sensorPin = A1; // select the input pin for the potentiometer int ledPin = 13;
int ledPin = 3; // select the pin for the LED int sensor Value=0;
int sensorValue = 0; // variable to store the value coming from the sensor
int interval = 500;
long long int starttime = 0;
int mapping = 0;
unsigned long mytime;
void setup() {
  Serial.begin(9600);
}

void loop() {
  mytime = millis();
  sensorValue = analogRead(sensorPin);

  //Serial.println(sensorValue);
  mapping=map(sensorValue,1,500,255,0);
  if(mapping<0){
    mapping = 0;
  }
  analogWrite(ledPin, mapping);
  
  //int light=255-sensorValue;
  //analogWrite(ledPin, light);
  if (mytime-starttime>=interval){
    Serial.println(sensorValue);
    Serial.println(mapping);
    starttime = mytime;
    if(sensorValue>10){
      Serial.println("Light comes");
    }
    else{
      Serial.println("No light");
    }
  }
}