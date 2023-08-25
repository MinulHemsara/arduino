#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// #include "DHT.h"

// #define DHTPIN D2     // Digital pin connected to the DHT sensor
// #define DHTTYPE DHT11   //#define DHTTYPE DHT11
// DHT dht11(DHTPIN, DHTTYPE);

#define BLYNK_TEMPLATE_ID "TMPL6YXu9CRTS"
#define BLYNK_TEMPLATE_NAME "Template 1"
#define BLYNK_AUTH_TOKEN "03WBAkM8xi6DRPLqDu9P_VSZb1pd8qBr"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "MohamedZumry";//Enter your WIFI name
char pass[] = "dlcd8553";//Enter your WIFI password


// BLYNK_WRITE(V0) {
//   digitalWrite(D0, param.asInt());
// }

BLYNK_WRITE(V1) {
  digitalWrite(D1, param.asInt());
}

void setup() {
  // pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  // Serial.begin(9600);
  // dht11.begin();
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {  
  Blynk.run();
  
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  // float h = dht11.readHumidity();
  // // Read temperature as Celsius (the default)
  // float t = dht11.readTemperature();
  // // Check if any reads failed and exit early (to try again).
  // if (isnan(h) || isnan(t)) {
  //   Serial.println(F("Failed to read from DHT sensor!"));
  //   return;
  // }
  // Blynk.virtualWrite(V2, t);
  // Serial.println("Temperature Value ");
  // Serial.print(t);
  // Blynk.virtualWrite(V3, h);
  // Serial.println("Humidity Value ");
  // Serial.print(h);  
}
