/*********************************************************************************
 * 
 *                             E E T P  N 4 6 5                                  *
 * 
 * *******************************************************************************/

/*===================[File header]===============================================*/
// File:                main.cpp
// Author:              Marcelo Castello (https://github.com/mcastellogh)
// Licence:             GPLV3+
// Version:             2.0.0
// Date:                Setiembre 2021
// Info:                Hola mundo con led

//=============== [Datos para almacenamiento] ======================================
// PCB:                 Escuela V1.0
// Plataforma:          ESP8266  
// Uso:                 Template
// Carpeta:             escuela
// Nombre de Proyecto:  led

// TODO:    
//        
//
// BUGS:    
//     
//                   
//
// COMMIT:  
//
// Para subir FileSystem: platformio run --target uploadfs

/*===================[Inclusiones]===============================================*/
#include <Arduino.h>
#include "interrupciones.h"

/*===================[Variables harcodeadas]=====================================*/
uint32_t        retardo         =   500;
const char *    tipo_device     =   "Led";
const char *    fversion        =   "1.0.0";

//===================[Macros]====================================================*/
#define         SERIAL_BAUDRATE     19200
#define         LED                 2

/*===================[Variables globales]========================================*/


/*===================[Variables externas]========================================*/

extern          bool                flag_seg;

//===================[Instancias]================================================*/



void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  delay(100);
  Serial.println(tipo_device);
  Serial.print("Version:");
  Serial.print(fversion);
  
  //--Pines
  pinMode(LED,OUTPUT);
  
  //--Pone en 0 el pin del led
  digitalWrite(LED, LOW);

  //--Configuración interrupción por timer
  noInterrupts();
  timer0_isr_init();
  timer0_attachInterrupt(timer0_ISR);
  timer0_write(ESP.getCycleCount() + 80000000L); // 80MHz == 1sec
  interrupts();
  delay(100);

}

void loop() {
  if (flag_seg){
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED,LOW);  
  }
}

