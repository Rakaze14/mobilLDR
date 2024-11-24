#define __SFR_OFFSET 0x00
#include "avr/io.h"

.global LDR_Read
.global LDR2_Read

// Fungsi untuk membaca LDR 1 (terhubung ke pin 8 -> bit 0 pada PINB)
LDR_Read:
    in r24, PINB          ; Baca register PINB (input dari port B)
    sbrs r24, 0           ; Memeriksa bit 0 (pin 8)
    rjmp LDR_NoLight      ; Lompat jika tidak ada cahaya
    ldi r24, 1            ; Jika ada cahaya, set r24 = 1
    ret                   ; Kembali dengan nilai 1 (cahaya terdeteksi)

LDR_NoLight:
    ldi r24, 0            ; Jika tidak ada cahaya, set r24 = 0
    ret                   ; Kembali dengan nilai 0 (cahaya tidak terdeteksi)

// Fungsi untuk membaca LDR 2 (terhubung ke pin 9 -> bit 1 pada PINB)
LDR2_Read:
    in r24, PINB          ; Baca register PINB (input dari port B)
    sbrs r24, 1           ; Memeriksa bit 1 (pin 9)
    rjmp LDR2_NoLight     ; Lompat jika tidak ada cahaya
    ldi r24, 1            ; Jika ada cahaya, set r24 = 1
    ret                   ; Kembali dengan nilai 1 (cahaya terdeteksi)

LDR2_NoLight:
    ldi r24, 0            ; Jika tidak ada cahaya, set r24 = 0
    ret                   ; Kembali dengan nilai 0 (cahaya tidak terdeteksi)
