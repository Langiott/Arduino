//sito web: https://www.mauroalfieri.it/elettronica/tutorial-arduino-interrupt.html

int ledRed      = 8;
int ledGreen    = 7;
int ledYellow   = 12;
int interrCount = 0;

void setup(){
  pinMode(ledRed,OUTPUT);
  pinMode(ledGreen,OUTPUT);
  pinMode(ledYellow,OUTPUT);

  digitalMode(ledRed,LOW);
  digitalMode(ledGreen,LOW);
  digitalMode(ledYellow,LOW);

  //RISING: si attiva quando passa da LOW a HIGH 

  attachInterrupt(0,interruptGiallo,RISING);

}

void loop() {

  interrCount++;
  digitalMode(ledRed,HIGH);
  digitalMode(ledGreen,LOW);
  delay(500);
  digitalMode(ledRed,LOW);
  digitalMode(ledGreen,HIGH);


  if(interrCount == 10 )
  {
    interrCount= 0;
    digitalWrite(ledYellow,LOW);
  }


}

void interruptGiallo(){
    digitalWrite(ledYellow,HIGH);
  }