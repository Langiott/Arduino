
#include <avr/wdt.h>


int ledRed = 3;

void setup() {
  int i = 0;
  Serial.begin(9600);                
  pinMode(2,INPUT_PULLUP);           
  pinMode(ledRed,OUTPUT);           
  digitalWrite(ledRed,LOW);
  while (Serial.available()) {       
   Serial.println("conf_iniziale");

   if(i>=1){
     digitalWrite(ledRed,HIGH);    
     delay(1000);                 
     digitalWrite(ledRed,LOW);
   }
   i+=1;
   wdt_enable(WDTO_8S);
   if (i=10000)  {
     wdt_disable();
   }           
   } 
}

void loop() {


  int butt = HIGH;              
  
  while(butt) {
  butt = digitalRead(2);
  delay(1000);
  Serial.println("ESEGUO 1° PARTE DEL CODICE");
  Serial.println("ESEGUI 2° PARTE DEL CODICE");
  }
  Serial.println("exit");      
  wdt_reset();
  

}
