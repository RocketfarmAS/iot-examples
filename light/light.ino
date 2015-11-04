
const int sensorPin = A0;

int sensorValue = 0;

void setup() {
  
  // Init usb logging
  Serial.begin(19200);
  
}

void loop() {
  
  // Read value. Returns 0 - 1023 (12 bit)
  sensorValue = analogRead(sensorPin);
  
  Serial.println(sensorValue);
  delay(100);

}
