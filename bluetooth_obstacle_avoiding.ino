//MakewithREX Bot controller android app
#include <NewPing.h>

//sensor pins
#define trig_pin A1 //analog input 1
#define echo_pin A2 //analog input 2
//in1 in2 in3 in4 4 5 6 7

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function

char getstr;
const int LeftMotorForward = 7;
const int LeftMotorBackward = 6;
const int RightMotorForward = 5;
const int RightMotorBackward = 4;

void _mForward()
{ 
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}
void _mBack()
{
  
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
}
void _mleft()
{
  
  digitalWrite(LeftMotorBackward, LOW); 
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}
void _mright()
{
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW); 
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  
}
void _mStop()
{
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void setup()
{ 
  
  Serial.begin(9600);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  distance = readPing();
  delay(100);
}
void loop()
  { 
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20){
    _mStop();
    getstr=Serial.read();
    if(getstr=='B'){
      _mBack();
    }
    delay(300);
  }

   else{ 
  getstr=Serial.read();
 if(getstr=='F')
  {
    _mForward();
  }
  else if(getstr=='B')
  {
    _mBack();
  }
  else if(getstr=='R')
  {
    _mleft();
  }
  else if(getstr=='L')
  {
    _mright();
  }
  else if(getstr=='X')
  {
     _mStop();     
  }
   }
   distance = readPing();
}
int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

