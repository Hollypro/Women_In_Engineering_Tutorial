#include <SoftwareSerial.h>
SoftwareSerial BT(10,11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){}
  Serial.println("HI!!!!!!");
  BT.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //if (BT.isListening()){Serial.println("Listening!!!");}
  if (BT.available()){Serial.println("im in");Serial.write(BT.read());}
}
