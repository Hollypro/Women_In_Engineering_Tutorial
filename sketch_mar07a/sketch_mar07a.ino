/*
Hi everyone!
My name is Hu-go, I hope you guys are having a nice day!
I'll explain what the code does at every step so that you may control the car from your phone!
*/

#include <Servo.h> //This tells the program to import some extra functions not usually needed.
#include <SoftwareSerial.h>

SoftwareSerial BT(0,1);

Servo turn;   //This is the name of our servo (the blue machine)
Servo power; //C is for continuous servo (the back wheels).

void checkCommand();
void modeChange();

int UltraTrig=3; //These are the pins which will connect to the ultrasonic sensor.
int UltraEcho=2; //The number corresponds to the pin number on the arduino board.

int LedPin=4;

int turnPin=6;
int powerPin=5;
int angle=40;
//The angle determines the direction of the car.
//70 is straight ahead
//100 is right
//40 is left

float UltraSens; //This will store the value given by the sensor, it can hold 15 decimal places (0 for integers)

int playMode = 0; // 0: stop mode; 1: smart stop; 2: roomba mode;
char command='F';// Command received from your phone
int  commandType=0;//0: useless command; 1:driving command; 2: mode change command

//-------------------------------------------------------------------------------------
void setup() {
  turn.attach(turnPin);
  power.attach(powerPin);
  //Tells the arduino that our servo is controlled by which pin
 
 
  pinMode(UltraTrig,OUTPUT); //This sets our pins as either input (collected data)
  pinMode(UltraEcho,INPUT);  //Or output (transmitted data)


  Serial.begin(9600); //This is for communication between different devices
  //In this case, it is between the blutooth module and the arduino.
  
  while(!Serial){
    delay(100);
    //This makes the arduino wait until serial begins to work.
    //The delay of 100ms is to prevent the arduino from looping too often while waiting.
  }
  
  turn.write(70); //Tells the car to begin as going straight ahead.
}

void loop() {
  turn.write(70);
  if(BT.available()){
    checkCommand();
    if(commandType==2){
      modeChange();
      }
    else if (commandType == 1 and playMode == 1){// in manual drive(playMode 1
      switch(command){
        case 'A': power.writeMicroseconds(2000);
          break;
        case 'B': power.writeMicroseconds(1000);
          break;
        case 'C': turn.write(40);
          break;
        case 'D': turn.write(100);
          break;
      }
     }
    else{
      // it is a useless command
      // or not in manual drive mode (playMode 2)
      // so we dont do anything
      }
    delay(200);
      
    }
  if(playMode == 0){ //stop mode
    power.writeMicroseconds(1500);
    }
  else if (playMode == 2){ // roomba mode
    roombaMode();
    }
}

//---------------------------------------------------------------------------------------
// Functions
//***********************************************************
// to determine the play mode
void checkCommand(){
  command = BT.read();
  switch(command){
      case 'A': case 'B': case 'C': case 'D':
        commandType = 1; // driving commands(speed or direction)
        break;
      case 'E': case 'F': case 'G': case 'H':
        commandType = 2; // play mode command
        break;
      default:  // not all the commands are used
        commandType = 0;
        break;
    }
  }

//***********************************************************
// 
void modeChange(){
  switch(command){
    case 'F': case 'G':// stop mode
      playMode = 0;
    case 'H':
      playMode = 1;
    case 'E': 
      playMode = 2;
    
    }
  }

//**************************************************************
//
void roombaMode(){
  
  }
//**********************************************************
//
void wall(){
  
  }
