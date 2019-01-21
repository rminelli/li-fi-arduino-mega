/* Roberto Minelli 
Universidad de Granda
2018
----------------
Arduino - Music Player
El circuito:
 * Pulsador - pin 2 and 3
 * Salida de audio - pin 46
 * Conexión SPI del módulo SD: 
 ** MOSI - pin 51
 ** MISO - pin 50
 ** SCK - pin 52
 ** CS - pin 53 
 */
 
#include "SD.h" //Librería para leer la tarjeta de memoria
#include "TMRpcm.h" //Librería para reproducir el audio
#include "SPI.h" //Librería SPI para la tarjeta de memoria

#define SD_ChipSelectPin 53 //Pin para seleción de chip - CS ( Chip Selection )

TMRpcm music; //Objeto llamado "music"

int Bt1 = 0; 
int Bt2 = 0;
boolean db1=true;
boolean db2=true;

void setup()
{

music.speakerPin = 46; //Salida de audio
Serial.begin(9600); //Serial Com para la depuración
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
return;
}
 pinMode(2,INPUT);  //Definir 2 como entrada digital.
 pinMode(3,INPUT);  //Definir 3 como entrada digital.
 
music.setVolume(7);    //   0 to 7. Establecer el nivel de volumen
music.quality(0);        //  Defini 1 para 2x sobremuestreo y 0 para normal
 
}



void loop()
{ 
  
  Bt1=digitalRead(2); 
  Bt2=digitalRead(3);

 
 if (Bt1 == LOW & db1 == true)  //Para Bt1 presionado, reproduce el archivo "1.wav"
    { 
      {music.play("1");}
      db1 = false;
      Serial.println("Bt1 presionado");
      
    
    }    
    if(Bt2 == LOW & db1 == true) //Para Bt2 presionado, reproduce el archivo "2.wav"
    { 
      {music.play("2");}
      db2 = false;
      Serial.println("Bt2 presionado");
    
    }

   if (digitalRead(2)==HIGH) // Evitar rebotes
  db1=true;

  if (digitalRead(3)==HIGH)  // Evitar rebotes
  db2=true;
}

