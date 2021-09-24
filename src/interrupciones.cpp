#include "interrupciones.h"

//--Variables locales
uint8_t seg=0;
uint8_t minu=0;
bool flag_seg=0;

void timer0_ISR (void) {
  flag_seg=~flag_seg;
  seg++;
  
  if(seg==60){
    seg=0;
    minu++;
  }
  if(minu==60) minu=0;
  

  timer0_write(ESP.getCycleCount() + 80000000L); // 80MHz == 1sec
}