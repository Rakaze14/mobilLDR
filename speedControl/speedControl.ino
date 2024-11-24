//Made By Kipli :>
//(づ｡◕‿‿◕｡)づ        〆(・∀・＠)
//*************************************************************************************************************************//

// Kecepatan default untuk motor A dan B
int speedA = 180; //Scala 0-255
int speedB = 180; 

extern "C" {
  uint8_t LDR_Read(void);
  uint8_t LDR2_Read(void);
}

void setup() {
  // Megatur pin motor sebagai OUTPUT
  pinMode(5, OUTPUT); // enA
  pinMode(6, OUTPUT); // enB
  pinMode(2, OUTPUT); // in1
  pinMode(3, OUTPUT); // in2
  pinMode(4, OUTPUT); // in3
  pinMode(7, OUTPUT); // in4

  // Mengatur pin LDR sebagai INPUT
  pinMode(8, INPUT);  // Digital pin 8 untuk LDR 1
  pinMode(9, INPUT);  // Digital pin 9 untuk LDR 2
}

void loop() {
  // Membaca kondisi LDR
  uint8_t ldrValue = LDR_DigitalRead();   
  uint8_t ldrValue2 = LDR2_DigitalRead(); 

  if (ldrValue) {
    // Jika LDR 1 mendeteksi cahaya, robot akan maju
    analogWrite(5, speedA);  
    analogWrite(6, speedB);  

    digitalWrite(2, HIGH);   
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);  
    digitalWrite(7, LOW);
  } else if (ldrValue2) {
    // Jika LDR 2 mendeteksi cahaya, robot akan mundur
    analogWrite(5, speedA); 
    analogWrite(6, speedB); 

    digitalWrite(2, LOW);    
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);    
    digitalWrite(7, HIGH);
  } else {
    // Jika tidak ada cahaya pada kedua LDR, robot berhenti
    analogWrite(5, 0);       
    analogWrite(6, 0);       

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
  }

  delay(100);
}
