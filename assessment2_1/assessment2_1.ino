#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
// #include "DHT.h"
 
#define FIREBASE_HOST "arduino-led-blink-default-rtdb.asia-southeast1.firebasedatabase.app" // Firebase host
#define FIREBASE_AUTH "YXKhQUW7ccdgIDzlehafnUBxLQz1kIlEt70hFKMc" //Firebase Auth code
#define WIFI_SSID "MohamedZumry" //Enter your wifi Name
#define WIFI_PASSWORD "dlcd8553" // Enter your password
int fireLEDStatus = 0;
int fireACBulbStatus = 0;
// float fireTemp = 0;  
// float fireHumid = 0;

// DHT dht11(D2, DHT11);
 
void setup() {
  Serial.begin(9600);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  
  // dht11.begin();
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

  fireLEDStatus = Firebase.getInt("DC_BULB");
  if (fireLEDStatus == 1) {
    Serial.println("Led Turned ON");
    digitalWrite(D0, HIGH);  
    
  }
  else if (fireLEDStatus == 0) {
    Serial.println("Led Turned OFF");
    digitalWrite(D0, LOW);
  }
  else {
    Serial.println("Command Error! Please send 0/1");
  }

  fireACBulbStatus = Firebase.getInt("AC_BULB");
  if (fireACBulbStatus == 1) {
    Serial.println("Bulb Turned ON");
    digitalWrite(D1, LOW);
delay(1000);
  }
  else if (fireACBulbStatus == 0) {
    Serial.println("Bulb Turned OFF");
    digitalWrite(D1, HIGH);
  }
  else {
    Serial.println("Command Error! Please send 0/1");
  }
}
