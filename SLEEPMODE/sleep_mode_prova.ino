//https://www.youtube.com/watch?v=iMC6eG24S9g
//http://donalmorrissey.blogspot.com/2010/04/arduino-external-interrupts.html

#include <avr/sleep.h>
const int interrupt = 3; 
const int led_Rosso = 13;

void setup() {

  pinMode(interrupt,INPUT_PULLUP);
  pinMode(led_Rosso,OUTPUT);

  Serial.begin(9600);
  Serial.println("SETUP_MODE");

}

void loop() {
  
  bool flag= true;
  while(flag){
  Serial.println("LOOP_MODE");
  digitalWrite(led_Rosso,HIGH);
  delay(5000);

  /*
  read_data();
  upload();
  sent_dat();
  */
  flag=false ;
  }
  Serial.println("SLEEP_MODE");
  startSleep();
}

void startSleep(){

  Serial.println("SLEEP_MODE");
  attachInterrupt(digitalPinToInterrupt(0),wakeup_interrupt,LOW);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_cpu();


}


void wakeup_interrupt(){
  Serial.println("WAKE UP");
  detachInterrupt(digitalPinToInterrupt(0));
  digitalWrite(led_Rosso,HIGH);
  sleep_disable();
}