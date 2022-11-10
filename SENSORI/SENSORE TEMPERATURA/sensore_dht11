#include <DHT.h>

#define DHTPIN 2;
#define DHTTYPE dht11;
DHT dht (DHTPIN,DHTTYPE);



void setup() {
  Serial.begin(9600);
  dht11.begin();

}

void loop() {

  delay(2000);
  float h =  dht.readHumidity();   
  float t =  dht.readTemperature(); //celsius
  float t_F =  dht.readTemperature(true); //fahrenheit

  if(isnan(h) || (isnan(t)) || (isnan(t_F)) ){

    Serial.begin("ERRORE DI LETTURA");
    return;

  }

  Serial.begin(F("HUMIDITY: "));
  Serialprintln(h);

  Serial.begin(F("TEMPERATURE: "));
  Serial.println(h);




}
