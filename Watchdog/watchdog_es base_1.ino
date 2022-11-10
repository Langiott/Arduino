//canale Arduino:https://create.arduino.cc/projecthub/rafitc/what-is-watchdog-timer-fffe20

#include <avr/wdt.h>

void setup() {

  Serial.begin(9600);
  Serial.println("SETUP STARTER: ");
  Serial.println("-------------------");

  delay(3000);
  wdt_enable(WDTO_4S);
  
}

void loop() {
  Serial.println("LOOP STARTER");
    for (int i = 0; i<5 ;i++){
      Serial.println("LOOP: ");
      Serial.println("i");

      Serial.println("-------------------");
      delay(1000);
      wdt_reset();


  }
  while(1){/*loop infinito*/}

}
