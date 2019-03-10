/*
 * Quadcopter Code for Engr7B Winter Quarter 2019
 * Team Name: X-traa
 * Last edited: 3/10/2019
 * 
 */

//Import Statements
#include <Servo.h>
#include <SPI.h>  
#include <Pixy2.h>

//Variables
  //Constants
  const int trigPin = 9;
  const int echoPin = 10;
  const int servoPinRed = 8;
  const int servoPinBlue = 7;
  const int ultraRangeFar = 150;
  const int ultraRangeNear = 130;
  const int sigRed = 1; //signature one for the pixy will be red
  const int sigBlue = 2; //signature two for the pixy will be blue
  
  //Non-Constants
  Pixy2 pixy;
  Servo servoRed;
  Servo servoBlue;
  int posRed = 0;
  int posBlue = 0;
  int distanceUltra = 1000;
  long duration;
  bool isRed = false;
  bool isBlue = false;
  
  
  
void UltraDetect(){
  //Use Ultrasonic Sensor to modify distanceUltra
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  //Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  //Calculating the distance
  distanceUltra= duration*0.034/2;
  
  //Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distanceUltra);
}

void PixyDetect(){
  //Use Pixy Camera to determine color and change isRed and isBlue to true or false
  int i = 1;
  uint16_t blocks;
  blocks = pixy.ccc.getBlocks();
  if(blocks == sigRed){
    isRed = true; 
  }if(blocks == sigBlue){
    isBlue = true;
  }
  
}

void Open(){
  if(isRed == true){
    //move posRed 90 deg clockwise
    servoRed.write(0);
    delay(600);
    posRed = 0;
  }else if(isBlue == true){
    //move posBlue 90 deg counter-clockwise
    servoBlue.write(180);
    delay(600);
    posBlue = 180;
  }
}

void Close(){
  //move posRed and
  //posBlue back to origin position (0)
  servoRed.write(90);
  servoBlue.write(90);
  delay(600);
  //reset redPos and bluePos
  posRed = 90;
  posBlue = 90;
}

void setup() {
  //Attaches the servo to the servo pin.
  servoRed.attach(servoPinRed);
  servoBlue.attach(servoPinBlue);
  //Sets the trigPin as an Output
  pinMode(trigPin, OUTPUT);
  //Sets the echoPin as an Input
  pinMode(echoPin, INPUT);
  //Starts the serial communication
  Serial.begin(9600);
}

void loop() {
  UltraDetect();
  PixyDetect();
  
  if(distanceUltra <= ultraRangeFar && distanceUltra >= ultraRangeNear){
    Open();
  }else{
    Close();
  }
}
