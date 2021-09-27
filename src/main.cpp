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
// BUGS:    xd
//     
//                   
//
// COMMIT:  
//
// Para subir FileSystem: platformio run --target uploadfs

/*===================[Inclusiones]===============================================*/
#include <Arduino.h>

/*===================[Variables harcodeadas]=====================================*/
uint32_t        retardo         =   500;
const char *    tipo_device     =   "Led";
const char *    fversion        =   "1.0.0";

//===================[Macros]====================================================*/
#define         SERIAL_BAUDRATE     19200
#define         LED                 2

/*===================[Variables globales]========================================*/


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

}

void loop() {
delay(retardo);
digitalWrite(LED,HIGH);
delay(retardo);
digitalWrite(LED,LOW);
}

