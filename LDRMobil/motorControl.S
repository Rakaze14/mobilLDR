#define __SFR_OFFSET 0x00
#include "avr/io.h"
.global LDR_DigitalRead
LDR_DigitalRead:
  in r24, PINB         
  sbrs r24, 0          
  ldi r24, 0           
  ret                  

LDR_DigitalRead_LightDetected:
  ldi r24, 1           
  ret                  

.global LDR2_DigitalRead
LDR2_DigitalRead:
  in r24, PINB        
  sbrs r24, 1         
  ldi r24, 0           
  ret                  

LDR2_DigitalRead_LightDetected:
  ldi r24, 1           
  ret                  