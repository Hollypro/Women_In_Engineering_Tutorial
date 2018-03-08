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
void roombaMode();
float ultrasonic();
bool wall();
void manualMode();

int UltraTrig=3; //These are the pins which will connect to the ultrasonic sensor.
int UltraEcho=2; //The number corresponds to the pin number on the arduino board.

int LedPin=4;

int turnPin=6;
int powerPin=5;
int av = 70;//angle value
int anglim[2]={40,100};// angle limits
//The angle determines the direction of the car.
//70 is straight ahead
//100 is right
//40 is left

int sv=1500;//speed level
int splim[2]={1000,2000};//speed limit

int playMode = 0; // 0: stop mode; 1: manual mode; 2: roomba mode;
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
  BT.begin(9600);
  turn.write(70); //Tells the car to begin as going straight ahead.
  Serial.println("Let's start!");
}

void loop() {
  if (playMode == 1 and wall()and sv > 1500){sv=1500;av=70;power.writeMicroseconds(sv);turn.write(av);}
  if(BT.available()){
    checkCommand();
    if(commandType==2){
      modeChange();
      }
    else if (commandType == 1 and playMode == 1){// in manual drive(playMode 1
     manualMode();
     }
    else{
      // it is a useless command
      // or not in manual drive mode (playMode 2)
      // so we dont do anything
      }
      
    }
  if(playMode == 0){ //stop mode
    power.writeMicroseconds(1500);
    }
  else if (playMode == 2){ // roomba mode
    roombaMode();
    }
  Serial.println(playMode);
}

//---------------------------------------------------------------------------------------
// Functions
//***********************************************************
// to determine the play mode
void checkCommand(){
  command = BT.read();
  Serial.println(command);
  if(command=='A' or command=='B' or command=='C' or command=='D' ){commandType = 1;}
  else if(command=='E' or command=='F' or command=='G' or command=='H' ){commandType = 2;}
  else{commandType=0;}
  }

//***********************************************************
// 
void modeChange(){
  switch(command){
    case 'F': case 'G':// stop mode
      playMode = 0;
      break;
    case 'H':
      playMode = 1;
      break;
    case 'E': 
      playMode = 2;
      break;
    
    }
  }

//**************************************************************
//
void manualMode(){
  if (wall() and command=='A'){sv=1500;av=70;power.writeMicroseconds(sv);turn.write(av);}
  else{
  switch(command){
        case 'A': // foward
          if(sv!= splim[1]){sv+=125;}
          power.writeMicroseconds(sv);
          break;
        case 'C': // back
          if(sv!= splim[0]){sv-=125;}
          power.writeMicroseconds(sv);
          break;
        case 'D': // left
          Serial.println("CD");
          if(av!= anglim[0]){av-=15;}
          turn.write(av);
          break;
        case 'B': // right
          Serial.println("CB");
          if(av!= anglim[1]){av+=15;}
          turn.write(av);
          break;
      }
  }
}
//***************************************************************88
//
void roombaMode(){
  if(!wall()){
    power.writeMicroseconds(1800);
    turn.write(70);
    }
  else{
    int temp;
    temp = millis()%2;
    temp = 40+temp*60;
    power.writeMicroseconds(1800);
    turn.write(temp);
    delay(2000);
    }
  }
//**********************************************************
//
bool wall(){
  if(ultrasonic()<25){
    return 1;// when a object detected
  }
  return 0;// when it is safe
  }

float ultrasonic() {

  float c = 343; // speed of sound (m/s) at 20 deg C and sea level
  float duration; // echo time duration in microseconds
  float distance; // distance in m
  
  // send echo pulse of 11us duration
  digitalWrite(UltraTrig, LOW); // start output low initially
  delayMicroseconds(2); // wait for 2 us
  digitalWrite(UltraTrig, HIGH); // make output high
  delayMicroseconds(11); // wait for 11 us
  digitalWrite(UltraTrig, LOW); // make the output low

  duration = pulseIn(UltraEcho, HIGH);

  //Serial.print("\nduration (us) = ");
  //Serial.print(duration); 
  
  duration *= 1.0e-6; // convert duration to seconds
  
  // 2*distance = speed * time -> distance = speed * time / 2
  distance = c * duration / 2; // distance in m
  
//  Serial.print("\ndistance (cm) = ");
//  Serial.print(distance*100);
  delay(100);
  return distance*100;
  
  // wait 100 ms between sensor measurements
  // if the delay is too small there could be measurement errors
  
}
