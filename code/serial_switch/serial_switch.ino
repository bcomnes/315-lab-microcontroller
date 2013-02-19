const int led1 = 9;
const int led2 = 10;

boolean led1State = false; //Value used to store the state of LED1
boolean led2State = false; //Value used to store the state of LED2

void setup() {
  // initialize serial communication:
  Serial.begin(9600); //Start a serial session
  pinMode(led1, OUTPUT); //set led1 and 2 pins as outputs
  pinMode(led2, OUTPUT);
  digitalWrite(led1, led1State); //Turn off both LEDs
  digitalWrite(led2, led2State);
}
void loop() {
  //Check to see if any incoming commands have been recived
  if (Serial.available() > 0) {
    int inInt = Serial.parseInt(); //Read what command it is
    switch (inInt) { //Decide what to do with the command
    case 1:    // If we get a 1 over serial
      if (led1State == false) {  //and led1 is off
        led1State = true; //set its state to on
        Serial.println("LED1 ON");  //and let us know
      }
      else {
        led1State = false;  //or if led1 is on turn it off
        Serial.println("LED1 OFF"); //tell is that its turning off
      }
      digitalWrite(led1, led1State); //and update its actual state
      break; //end case 1
    case 2:    //if we get an incoming 2
      if (led2State == false) { //and if led2 is off
        led2State = true;  //set its state to on
        Serial.println("LED2 ON"); // let us know
      }
      else {  //or if its already on
        led2State = false;  //set its state to off
        Serial.println("LED1 OFF"); //and let us know
      }
      digitalWrite(led2, led2State); //update its actual state
      break; // end case 2
    case 0: //if someone sends us a 0
      led1State = false; //turn off both leds
      led2State = false;
      digitalWrite(led1, led1State);
      digitalWrite(led2, led2State);
      Serial.println("LEDS OFF"); //and let us know
      break; //end case 0
    default:
      Serial.println(Serial.read()); //if we get something else just print it
      }
    }
  }

