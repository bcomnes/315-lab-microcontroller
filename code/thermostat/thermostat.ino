const int threshold = A0;  // threshold set with 10k pot
const int temp = A1; // TMP36 Temp sensor
const int led = 9; //LED Pin

int thresholdValue = 0;        // value used to store threshold value from the pot
int tempValue = 0;        // value used to store temp read from the temp sensor
boolean ledState = false; // value used to write the led state

void setup() {
  digitalWrite(led, ledState);
  Serial.begin(9600); 
}

void loop() {
  // read the pot value and map it to the right scale
  thresholdValue = map(analogRead(threshold),0,1023,0,255);
  tempValue = analogRead(temp); // read the temp
  
  if (tempValue > thresholdValue) {
    ledState = true; //if temp > threshold, turn on LED
  }
  else {
    ledState = false; //if temp < threshold, turn off LED
  }
  digitalWrite(led,ledState); // This writes the state determined above
  
  // print the results to the serial monitor:
  Serial.print("thresholdValue = " );                       
  Serial.print(thresholdValue);      
  Serial.print("\t tempValue = ");
  Serial.print(tempValue);
  Serial.print("\t LED on?: ");
  Serial.println(ledState);

  delay(2); //Small settle delay for ADC   
}
