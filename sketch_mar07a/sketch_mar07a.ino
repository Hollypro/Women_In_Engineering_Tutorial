/*
Hi everyone!
My name is Hugo, I hope you guys are having a nice day!
I'll explain what the code does at every step so that you may control the car from your phone!
*/

#include <Servo.h> //This tells the program to import some extra functions not usually needed.
// #include <BTSerial.h>

Servo serv;   //This is the name of our servo (the blue machine)

int UltraTrig=12; //These are the pins which will connect to the ultrasonic sensor.
int UltraEcho=11; //The number corresponds to the pin number on the arduino board.

int MotorControlPin1=5;  //These are the pins for the motor controller (the black block)
int MotorControlPin2=6;

int ServPin=3;
int angle=40;
//The angle determines the direction of the car.
//70 is straight ahead
//100 is right
//40 is left

float UltraSens; //This will store the value given by the sensor, it can hold 15 decimal places (0 for integers)

int playMode = 0; // 0: stop mode; 1: drive mode; 2: smart stop; 3: roomba mode;

int command;// Command received from your phone

//-------------------------------------------------------------------------------------
void setup() {
  serv.attach(ServPin);
  //Tells the arduino that our servo is controlled by ServPin
 
  pinMode(UltraTrig,OUTPUT); //This sets our pins as either input (collected data)
  pinMode(UltraEcho,INPUT);  //Or output (transmitted data)
 
  pinMode(MotorControlPin1,OUTPUT);
  pinMode(MotorControlPin2,OUTPUT);

  Serial.begin(9600); //This is for communication between different devices
  //In this case, it is between the blutooth module and the arduino.
  
  while(!Serial){
    delay(100);
    //This makes the arduino wait until serial begins to work.
    //The delay of 100ms is to prevent the arduino from looping too often while waiting.
  }
  
  serv.write(70); //Tells the car to begin as going straight ahead.
}

void loop() {
  if(BT.available()){
    checkMode();
    
    
    
    }
}

//---------------------------------------------------------------------------------------
// Functions
//***********************************************************
// to determine the play mode
void checkMode(){
  int newC;
  newC = BT.read();
  uselessCommand = (newC==)
  if(uselessCommand){return;}
  }

//***********************************************************
