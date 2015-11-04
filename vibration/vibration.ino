

const int knockSensor = A0; // the piezo is connected to analog pin 0
const int threshold = 400;  // threshold value to decide when the detected sound is a knock or not

int sensorReading = 0;      // variable to store the value read from the sensor pin
int ledState = LOW;         // variable used to store the last LED status, to toggle the light

void setup() {
  
  // Init usb logging
  Serial.begin(19200);
  
}

void loop() {
  
  sensorReading = analogRead(knockSensor);
  if (sensorReading >= threshold) {
    Serial.println("Knock!");

    // Poor mans debounce :)
    delay(150);
  }
  
  delay(10);  // delay to avoid overloading the serial port buffer
  
}
