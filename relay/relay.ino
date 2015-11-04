int relayPin = 5;

void setup() {

  // Init digital port
  pinMode(relayPin, OUTPUT);
  
  // Init usb logging
  Serial.begin(19200);

}

void loop() {
  
  digitalWrite(relayPin, HIGH);
  delay(1000);
  
  digitalWrite(relayPin, LOW);
  delay(1000);

}
