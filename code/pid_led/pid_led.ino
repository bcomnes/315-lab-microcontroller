#include <PID_v1.h>
const int photores = A0;
const int pot = A1;
const int led = 9;
double lightLevel;

// Tuning parameters
const double Kp=0.01;
const double Ki=90;
const double Kd=0.001;

double Setpoint, Input, Output;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
const int sampleRate = 1;

// Communication setup
const long serialPing = 500; 
// Serial pingback interval in milliseconds
unsigned long now = 0; 
// placehodler for current timestamp
unsigned long lastMessage = 0; 
// last message timestamp.

void setup(){
  lightLevel = analogRead(photores);
  Input = map(lightLevel, 0, 1024, 0, 255); 
  Setpoint = map(analogRead(pot), 0, 1024, 0, 255);
  Serial.begin(9600);
  myPID.SetMode(AUTOMATIC); 
  myPID.SetSampleTime(sampleRate);
  
  Serial.println("Begin"); // Hello World!
  lastMessage = millis(); // timestamp
}

void loop(){
  Setpoint = map(analogRead(pot), 0, 1024, 0, 255);
  lightLevel = analogRead(photores);
  Input = map(lightLevel, 0, 900, 0, 255); 
  myPID.Compute();
  analogWrite(led, Output);
  
  now = millis();
  if(now - lastMessage > serialPing) {
    // this should execute less frequently
    // send a message back to the mother ship
    Serial.print("Setpoint = ");
    Serial.print(Setpoint);
    Serial.print(" Input = ");
    Serial.print(Input);
    Serial.print(" Output = ");
    Serial.print(Output);
    Serial.print("\n");
    
    lastMessage = now; 
    //update the time stamp. 
  }
  
}
