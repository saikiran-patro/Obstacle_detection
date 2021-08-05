/*
* Ultrasonic Sensor HC-SR04 interfacing with Arduino.
*/
// defining the pins
const int trigPin = 9;
const int echoPin = 10;
int led1=3; //RED
int led2=4;//ORANGE
int led3=5;//GREEN
// defining variables
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
if(distance<10)
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
}
else if(distance>10 and distance<30)
{
  digitalWrite(led1,LOW);   
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
   
}
else
{
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,HIGH);
}
// Prints the distance on the Serial Monitor
delay(1000);
Serial.print("Distance: ");
Serial.println(distance);
}
