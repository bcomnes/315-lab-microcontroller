const int led = 9;      // the pin that the LED is attached to
const int pot = A0;     // A0 will be the analog input channel
int sensorValue = 0;    // this will store the value read from the pot
int outputValue = 0;    // this is the value sent to our pwm pin

void setup()  { 
  pinMode(led, OUTPUT); // declare pin 9 to be an output
  Serial.begin(9600); // Open a serial monitor at 9600 baud
} 
void loop()  { 
  sensorValue = analogRead(pot); // store pot value in sensorValue
  outputValue = map(sensorValue, 0, 1023, 0, 255); // map sensorValue to correct range
  analogWrite(led, outputValue); // write the analog out value to led:
  
  Serial.print("sensor = " ); // print the results to the serial monitor:
  Serial.print(sensorValue);      
  Serial.print("\t output = ");      
  Serial.println(outputValue); 

  delay(2);  // wait 2 milliseconds for daq to settle 
}
