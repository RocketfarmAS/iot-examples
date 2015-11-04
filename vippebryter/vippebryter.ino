void setup() {
  Serial.begin(19200);
  pinMode(2, INPUT_PULLUP);  
  pinMode(3, INPUT_PULLUP);  
}

void loop() {
  bool a = digitalRead(2);
  bool b = digitalRead(3);

  Serial.print("Status er");
  if(a){
    Serial.println("A");
  }else{
    Serial.println("B");
  }

  delay(1000);

}
