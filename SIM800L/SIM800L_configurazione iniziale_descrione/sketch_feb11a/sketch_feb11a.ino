#include <SoftwareSerial.h>

/*ho chiamato la porta : sim800 perche i pin 3 e 2 
dell' arduino si collegano con i pin della sim800l */

SoftwareSerial sim800(3,2); //tx e px
void setup() {
  sim800.begin(9600);
  Serial.begin(9600);
  Serial.println("PRONTO");
  delay(1000);

  sim800.printn("AT");
  updateSerial();
  sim800.printn("AT+CSQ");
  updateSerial();
  sim800.printn("AT+CCID");
  updateSerial();
  sim800.printn("AT+CREG?");
  updateSerial();

}

void loop() {
 updateSerial();
}

void updateSerial(){
  delay(500)

  while (Serial.available()){
   sim800.write(Serial.read());
 } 
 while (sim800.available()){
   Serial.write(sim800.read());
 } 

} 
//canale yuotube :https://www.youtube.com/watch?v=zvluM-YI-0E
//migliore sim800l: things mobile, consuma poco, 10MB al mese 


//comandi : li pio fare in comdo diretto o automatico nella classe vid setup

AT      - dovrebbe rispondere con ok
AT+CSQ  - nell esempio appena mando il comando risponde con 21 ,0
          per capire se cè segnale, range da [0,30],se 21 allora buono
AT+CCID - serve per vedere se si possa usare e leggiamo informazioni sulla sim
AT-CREG? -vedo se è registrata sulla rete nell es:0,5 e riceve OK
          se registrata la rete ho tre casi , cio me lo dice il led della sim800l
          -caso1(lampeggia 1 sec): il modulo attivo ma non si è connesso alla rete
          -caso2(lampeggia 2 sec): connessa alla rete 
          -caso3(lampeggia 3 sec): attivata rete cellulare e puoi ricevere e mandare dati

AT+CMGF=1- configurare lo scambio di informazioni in modalita testo, cioe sms









