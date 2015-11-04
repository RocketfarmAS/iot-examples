
int ledPin = 4;      // Digital 2 pin
int ledState = LOW;

void setup() {
  
  // Set up led pin
  pinMode(ledPin, OUTPUT);
  
  // Init usb logging
  Serial.begin(19200);

}

void loop() {
  
  // Toggle state
  if(ledState == LOW){
    ledState = HIGH;
  } else {
    ledState = LOW;
  }
  
  // Set led state
  digitalWrite(ledPin, ledState);
  
  // Flash with 2Hz (500 ms period)
  delay(250);
}
