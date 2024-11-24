extern "C" {
  uint8_t LDR_DigitalRead(void);
  uint8_t LDR2_DigitalRead(void);
}

void setup() {
  pinMode(4, INPUT);  // Digital pin 4 for first output
  pinMode(5, INPUT);  // Digital pin 5 for first output
  pinMode(6, INPUT);  // Digital pin 6 for second output
  pinMode(7, INPUT);  // Digital pin 7 for second output

}

void loop() {
  uint8_t ldrValue = LDR_DigitalRead();   // Read dari LDR 1
  uint8_t ldrValue2 = LDR2_DigitalRead(); // Read dari LDR 2
  
  // Control
  if (ldrValue) {
    digitalWrite(7, HIGH);  
    digitalWrite(5, HIGH);  
  } else {
    digitalWrite(7, LOW);   
    digitalWrite(5, LOW);   
  }

  
  if (ldrValue2) {
    digitalWrite(6, HIGH); 
    digitalWrite(4, HIGH);  
  } else {
    digitalWrite(6, LOW);  
    digitalWrite(4, LOW);  
  }

  delay(100); 
}