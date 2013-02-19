#include <PID_v1.h>
const int photores = A0; // Photo resistor input
const int pot = A1; // Potentiometer input
const int led = 9; // LED output
double lightLevel; //variable that stores the incoming light level

// Tuning parameters
float Kp=0;
float Ki=10;
float Kd=0;

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
    if (Serial.available() > 0) {
      for (int x = 0; x < 4; x++) {
        switch (x) {
          case 0:
            Kp = Serial.parseFloat();
            break;
          case 1:
            Ki = Serial.parseFloat();
            break;
          case 2:
            Kd = Serial.parseFloat();
            break;
          case 3:
            for (int y = Serial.available(); y == 0; y--) {
              Serial.read();
            }
            break;
        }
      }
      Serial.print(" Kp,Ki,Kd = ");
      Serial.print(Kp);
      Serial.print(",");
      Serial.print(Ki);
      Serial.print(",");
      Serial.println(Kd);
      myPID.SetTunings(Kp, Ki, Kd);
    }
    
    lastMessage = now; 
    //update the time stamp. 
  }
  
}
