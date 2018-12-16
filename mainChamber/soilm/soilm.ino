int sensorPin = A0;    // select the input pin for the Soil moisture sensor
int sensorValue = 0;  // variable to store the value coming from the sensor
int sensorVCC = 10;
 
void setup() {
   Serial.begin(9600);  
   pinMode(sensorVCC, OUTPUT); 
   digitalWrite(sensorVCC, LOW);
}
 
void loop() {
  // power the sensor
  digitalWrite(sensorVCC, HIGH);
  //delay(10); //make sure the sensor is powered
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin); 
  //stop power 
  //digitalWrite(sensorVCC, LOW);  
  //wait
  delay(100);//delay time change according to your need          
  Serial.print("sensor = " );                       
  Serial.println(sensorValue);                   
}

// Value range: 
// 0 ~ 300 : Dry Soil
// 300 ~ 700 : Humid Soil
// 700 ~ 950 : in Water.
 
