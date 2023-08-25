//Include the library
#include <MQUnifiedsensor.h>
/************************Hardware Related Macros************************************/
#define         Board                   ("ESP8266")
#define         Pin                     (A0)  //Analog input 3 of your arduino
/***********************Software Related Macros************************************/
#define         Type                    ("MQ-4") //MQ3
#define         Voltage_Resolution      (3) // 3V3 <- IMPORTANT
#define         ADC_Bit_Resolution      (10) // For ESP8266
#define         RatioMQ3CleanAir        (60)
/*****************************Globals***********************************************/
MQUnifiedsensor MQ4(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin, Type);
/*****************************Globals***********************************************/

void setup() {
  Serial.begin(9600);
  MQ4.init();
}

void loop() {
  MQ4.update(); // Update data, the arduino will read the voltage from the analog pin
  MQ4.readSensor(); // Sensor will read PPM concentration using the model, a and b values set previously or from the setup
  MQ4.serialDebug(); // Will print the table on the serial port
  delay(500); //Sampling frequency
}
