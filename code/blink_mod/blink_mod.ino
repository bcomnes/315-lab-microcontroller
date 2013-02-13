int led = 13;
int wait = 100; // Time to wait before blinking

void setup() {                
  pinMode(led, OUTPUT);     
} 

void loop() {
  digitalWrite(led, HIGH);   
  delay(wait);  //Wait for the ammount declaired in the wait variable         
  digitalWrite(led, LOW);    
  delay(wait);  //Wait for the ammount declaired in the wait variable        
}
