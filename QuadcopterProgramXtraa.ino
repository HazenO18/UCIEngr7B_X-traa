/*
 * Quadcopter Code for Engr7B Winter Quarter 2019
 * Team Name: X-traa
 */

//Imports
#include <Servo.h>
#include <SPI.h>  
#include "TPixy2.h"

//Variables
  //Constants
const int trigPin = 9;
const int echoPin = 10;

  //Non-Constants
TPixy2 pixy();
Servo servoRed;
Servo servoBlue;
int posRed = 0;
int posBlue = 0;
int distanceUltra = 1000

void UltraDetect(){
  //Use Ultrasonic Sensor to modify distanceUltra
}

void PixyDetect(){
  //Use Pixy Camera to determine color
}

void setup() {
  servo.attach(3);  // attaches the servo on pin 3 to the servo object
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  UltraDetect();
  PixyDetect();
}
