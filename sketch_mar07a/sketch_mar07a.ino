/*
Hi everyone!
My name is Hugo, I hope you guys are having a nice day!
I'll explain what the code does at every step so that you may control the car from your phone!
*/

#include <servo.h> //This tells the program to import some extra functions not usually needed.
#include <BTSerial.h>

Servo serv;   //This is the name of our servo (the blue machine)

int UltraTrig=12; //These are the pins which will connect to the ultrasonic sensor.
int UltraEcho=11; //The number corresponds to the pin number on the arduino board.

int MotorControlPin1=10;  //These are the pins for the motor controller (the black block)
int MotorControlPin2=9;

float UltraSens;          //This will store the value given by the sensor, it can hold 15 decimal places (0 for integers)


void setup() {
  pinMode(UltraTrig,OUTPUT);
  pinMode(UltraEcho,OUTPUT);
 
  pinMode(MotorControlPin1,OUTPUT);
  pinMode(MotorControlPin2,OUTPUT);

  Serial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  Serial.
 
}
