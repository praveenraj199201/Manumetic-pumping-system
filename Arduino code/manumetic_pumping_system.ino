// this is a project for the smart pump system by the rk here we take a value echopin only input 

const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;
                            
long duration;
int distance;
int safetyDistance;
             
void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); 
}
  
void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
 

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);


 

duration = pulseIn(echoPin, HIGH);
 

distance= duration*0.034/2;
 
safetyDistance = distance;
if (safetyDistance <=10 )   
{
  digitalWrite(buzzer,LOW);
  digitalWrite(ledPin, LOW);
}
else if (safetyDistance ==200 ){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
 

Serial.print("Distance: ");
Serial.println(distance);
}                                  
