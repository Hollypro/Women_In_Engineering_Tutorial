//Blynk
#define BLYNK_PRINT Serial // print out blynk logo on serial monitor

#include <BlynkSimpleSerialBLE.h> //access to Blynk library
#include <SoftwareSerial.h> //bluetooth module library
SoftwareSerial SerialBLE(0, 1); // RX, TX is at pin 10 & 11 instead of pin 0,1

char auth[] = "c7dfed645515466daa6aaca2d3b01a94";//authorization code to access the app Blynk

#include <Servo.h>

int reading0;
BLYNK_WRITE(V0) {
  reading0 = param.asInt();
  Serial.print("V0's value is: ");
  Serial.println(reading0);
}
int reading1;
//virtual button 
BLYNK_WRITE(V1) {
  reading1 = param.asInt();
  Serial.print("V1's value is: ");
  Serial.println(reading1);
}
int reading2;
BLYNK_WRITE(V2) {
  reading2= param.asInt();
  Serial.print("V2's value is: ");
  Serial.println(reading2);
}
int reading3;
BLYNK_WRITE(V3) {
  reading3= param.asInt();
  Serial.print("V3's value is: ");
  Serial.println(reading3);
}
int reading4;
BLYNK_WRITE(V4) {
  reading4 = param.asInt();
  Serial.print("V4's value is: ");
  Serial.println(reading4);
}



//int reset=3;
void setup() {
  Serial.begin(9600); 
  //connect to Blynk app
  Serial.println("Blynk Servo Car");
  delay(2000);
  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);
  Serial.println("Waiting for connections...");
  
}

////////////////////////////////////////////////
void loop(){
  Blynk.run();
  }
