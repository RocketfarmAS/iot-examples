
// Install libraries: Click Sketch > include library > manage library > "DallasTemperature" and "OneWire"

#include <OneWire.h>
#include <DallasTemperature.h>

int temperaturePin = 2;

// Initialize OnwWiere bus on pin
OneWire oneWire(temperaturePin);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensor(&oneWire);

void setup() {
  
  // Init usb logging
  Serial.begin(19200);
  
  // Initialize library
  sensor.begin();
}

void loop() {
  
  Serial.print("Requesting temperatures...");
  sensor.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");

  Serial.print("Temperature for Device 1 is: ");
  Serial.println(sensor.getTempCByIndex(0)); // Why "byIndex"? 
    // You can have more than one IC on the same bus. 
    // 0 refers to the first IC on the wire

  delay(1000);
}
