void setup() {
  pinMode(4, INPUT);
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  if (digitalRead(4)== HIGH) {
    Serial.write(1);
    Serial.println("Pressed");
  } else {
    Serial.write(0);
    Serial.println("Released");
  }
  
}
