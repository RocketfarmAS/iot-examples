const int potPin = A0;

void setup() {
  Serial.begin(19200);
  
  Serial.println("Starting sketch");
}

void loop() {
  
  // Return 0 - 1023
  int value = analogRead(potPin);
  float p = ((float)value) / 1023.0;
  
  Serial.print("Potmeter position: ");
  Serial.print(p * 100);
  Serial.println(" %");
  delay(300);
}
