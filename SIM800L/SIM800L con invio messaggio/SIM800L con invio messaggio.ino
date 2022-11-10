#include <SoftwareSerial.h>
SoftwareSerial sim800(3,2); //tx e px

void setup() {

  pinMode(4,INPUT); //PIN RANDOM
  Serial.begin(9600);
  sim800.begin(9600);
  Serial.println("PRONTO");
  delay(1000);

  sim800.printn("AT");
  updateSerial();//SE NON è PRONTO , PROTREI BLOCCARE TUTTO IL LOOP

  sim800.printn("AT+CMGF=1");
  updateSerial();


}

//DEVO INDIVIDUARE IL FRONTE DI DISCESA DEL PULSANTE
//COSI DA INVIASE SMS SOLO NEL FRONTE DI DISCESA 

int bt , prevbt;

void loop() {
  bt= digitalRead(4);

  if (prevbt && !bt){

    Serial.println("SMS: HO LETTO SUL SENSO T=2");
    sim800.println("AT+CMS=\"+3933961978\"");
    updateSerial();
    sim800.println("SMS: Hello Andrea");
    updateSerial();
    
    sim800.write(26);//chiudi procedure 
    Serial.println("SMS INVIATO");
  }
  prevbt=bt;
}

void updateSerial() {
  delay(500)

  while (Serial.available()) {
   sim800.write(Serial.read());
 } 
 while (sim800.available()){
   Serial.write(sim800.read());
 } 
} 
