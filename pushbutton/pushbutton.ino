

int buttonPin = 2;      // Digital 2 pin
int buttonState = 0;    // variable for reading the pushbutton status

void setup() {
  // initialize the pushbutton pin as an input (with pullup):
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Init usb logging
  Serial.begin(19200);
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    Serial.println("Button is up");
  } 
  else {
    Serial.println("Button is down");
  }
  
  // Sample the button every 100 ms
  delay(100);
}
