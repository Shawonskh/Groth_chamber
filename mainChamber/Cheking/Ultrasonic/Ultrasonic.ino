// Datasheet for Ultrasonic Ranging Module HC - SR04
// https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf
// Don't forget to check PINS!!!

int echoPin = 2;
int trigPin = 3;
int delay_us = 10; // <--- YOU HAVE TO FIND THE CORRECT VALUE FROM THE DATASHEET
long distance_mm = 0;
long duration_us;

void setup()  {
  // YOUR SETUP CODE GOES HERE

  // In this section you should initialize serial connection to Arduino
  Serial.begin(9600);
  // and set echoPin and trigPin to correct modes
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  // To generate the ultrasound we need to
  // set the trigPin to HIGH state for correct ammount of µs.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(delay_us);
  digitalWrite(trigPin, LOW);

  // Read the pulse HIGH state on echo pin
  // the length of the pulse in microseconds
  duration_us = pulseIn(echoPin, HIGH);

  // YOU HAVE TO CALCULATE THE distance_mm BASED ON THE duration_us
  // FIND THE FORMULA FROM THE DATASHEET AND IMPLEMENT IT HERE

  distance_mm = duration_us * 340 / 2 / 1000; //(high level time×velocity of sound(340M/S) / 2

  Serial.println(distance_mm);
  Serial.println("dist");
  delay(1000);
}
