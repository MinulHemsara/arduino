#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
 
#define FIREBASE_HOST "arduino-led-blink-default-rtdb.asia-southeast1.firebasedatabase.app" // Firebase host
#define FIREBASE_AUTH "YXKhQUW7ccdgIDzlehafnUBxLQz1kIlEt70hFKMc" //Firebase Auth code
#define WIFI_SSID "MohamedZumry" //Enter your wifi Name
#define WIFI_PASSWORD "dlcd8553" // Enter your password
// int fireLEDStatus = 0;
int fireLEDStatus2 = 0;
 
void setup() {
  Serial.begin(9600);
  pinMode(D1, OUTPUT);
  
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

  fireLEDStatus2 = Firebase.getInt("LED_STATUS2");
  if (fireLEDStatus2 == 1) {
    Serial.println("Led 2 Turned ON");
    digitalWrite(D1, HIGH);
  }
  else if (fireLEDStatus2 == 0) {
    Serial.println("Led 2 Turned OFF");
    digitalWrite(D1, LOW);
  }
  else {
    Serial.println("Command Error! Please send 0/1");
  }
} 
