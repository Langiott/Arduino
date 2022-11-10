//canale YUOTUBE:https://www.youtube.com/watch?v=qQ3ABYArLos
/*
Codice di programma,premo un pulsante, vado a prende contenuto che ho dentro un file chiamato txt 
che è contenuto in un sito http , vado a vedere cosa cè scritto e in base a quello 
accendo o spengo un led

*/CHIAMATA AD UN WEB PAGE , CON 
#include <SoftwareSerial.h>
SoftwareSerial sim800(3,2); //tx e px

void setup() {

  pinMode(4,INPUT); //PIN PULSANTE 
  pinMode(13,OUTPUT)//PIN LED
  Serial.begin(9600);
  sim800.begin(9600);

  Serial.println("PRONTO");
  delay(1000);

  sim800.printn("AT"); //PRONTO
  risposta("OK");

  sim800.printn("AT+CSQ");//TEST SEGNALE
  risposta("OK");

  sim800.printn("AT+CFUN=1");
  risposta("OK");

  sim800.printn("AT+CGATT=1");//COLLEGO ALLA RETE DATI (GPS)
  risposta("OK");

  sim800.printn("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");//DICHIARO HO COLLEGMNETO GPS
  risposta("OK");

  sim800.printn("AT+SAPBR=3,1,\"APN\",\"TM\"");//DICHIARO OPERATORE TELEFONICO (ES: TIM)
  risposta("OK");

  sim800.printn("AT+SAPBR=1,1"); // CONFIGURO LE SCELTE DI PRIMA
  risposta("OK");


  sim800.printn("AT+HTTPINIT=\"CID\",1"); // SIAMO PRONTI PER FARE UNA CHIAMATA http
  risposta("OK");

  
  sim800.printn("AT+HTTPINIT=\"REDIR\",1"); 
  risposta("OK");

  sim800.printn("AT+HTTPINIT=\"URL\",\"http:\\www.zeppelinmaking.it/led.txt"); 
  risposta("OK");

}


void loop() {
      
       if (digitalRead(4){//SE PREMUTO IL PULSANTE 
         sim800.printn("AT+HTTPACTION=0"); //COMANDO EFFETTIVO
         risposta("OK");
         delay (5000);
         sim800.printn("AT+HTTPREAD");//LEGGE E VANDA MSG NELLA SERIALE
         if (risposta('on')==1 ){
           digitalWrite(13,HIGH);
         }else{
           digitalWrite(13,LOW);
         }
         
         delay (5000);


       }

  
}

int risposta(String txt){
  int n = 0;
  String app= "";
  bool LOOP = true;
  delay(500);

  while(LOOP)  {
    //fin tanto sim880 sta lavorando
    if(sim800.available())  {
      //cattura char di sim
      char c = sim800.read();
      //auotomaatizzo le varie risposte mettendomi nel caso ho un "vai a capo"
      if (c == '\n'){

        Serial.println("RX"+app+"#");
        //se lo riesce a prendere e la risposta è giusta il loop chiude 
        if(app == txt) {
          LOOP = false;
          n=1; //il risultato e quello giusto

        }else if (app== 'OK'){
          LOOP = false;
          n=1;
        }else if (app == 'ERROR'){
           LOOP = false;
          n=-1; //nonn ho ottenuto quello voluto , rivaluto quello che devo fare 
        }
        
      }else if ( c== '\r') {
        
      }else{
        app+=c; //accodamento

      }
    }


  }
  return n;
}