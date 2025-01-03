//Made By Kipli :>
//(づ｡◕‿‿◕｡)づ        〆(・∀・＠)
//*************************************************************************************************************************//

extern "C" {
  uint8_t LDR_DigitalRead(void);
  uint8_t LDR2_DigitalRead(void);
}

void setup() {
  pinMode(4, INPUT);  // In1
  pinMode(5, INPUT);  // In2
  pinMode(6, INPUT);  // In3
  pinMode(7, INPUT);  // In4

}

void loop() {
  uint8_t ldrValue = LDR_DigitalRead();   // Membaca dari LDR 1
  uint8_t ldrValue2 = LDR2_DigitalRead(); // Membaca dari LDR 2
  
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