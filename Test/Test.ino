#include <SoftwareSerial.h>
SoftwareSerial BT(0,1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){}
  Serial.println("HI!!!!!!");
  BT.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BT.available()){Serial.write(BT.read());}
}
