#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include "DHT.h"
 
#define FIREBASE_HOST "arduino-led-blink-default-rtdb.asia-southeast1.firebasedatabase.app" // Firebase host
#define FIREBASE_AUTH "YXKhQUW7ccdgIDzlehafnUBxLQz1kIlEt70hFKMc" //Firebase Auth code
#define WIFI_SSID "MohamedZumry" //Enter your wifi Name
#define WIFI_PASSWORD "dlcd8553" // Enter your password
int fireLEDStatus = 0;
// int fireLEDStatus2 = 0;
float fireTemp = 0;
float fireHumid = 0;

DHT dht11(D2, DHT11);
 
void setup() {
  Serial.begin(9600);
  pinMode(D0, OUTPUT);
  
  dht11.begin();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected.");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 // Firebase.set("LED_STATUS", 0);
}
 
void loop() {
  delay(1000);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht11.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht11.readTemperature();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Firebase.setFloat("Humid", h);
  Firebase.setFloat("Temp", t);
  
  fireLEDStatus = Firebase.getInt("LED_STATUS1");
  if (fireLEDStatus == 1) {
    Serial.println("Led Turned ON");
    digitalWrite(D0, HIGH);  
    delay(1000);
  }
  else if (fireLEDStatus == 0) {
    Serial.println("Led Turned OFF");
    digitalWrite(D0, LOW);
  }
  else {
    Serial.println("Command Error! Please send 0/1");
  }
} 
