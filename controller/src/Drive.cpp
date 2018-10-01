#include "Drive.h"

int motorSpeedA = 0;
int motorSpeedB = 0;

Drive::Drive(int _in1, int _in2, int _in3, int _in4, int _motorPin1, int _motorPin2){
  in1 = _in1;
  in2 = _in2;
  in3 = _in3;
  in4 = _in4;
  motorPin1 = _motorPin1;
  motorPin2 = _motorPin2;

  motorSpeedA = 0;
  motorSpeedB = 0;

  ledcSetup(0, 2000, 8);
  ledcAttachPin(motorPin1, 0);
  ledcSetup(1, 2000, 8);
  ledcAttachPin(motorPin2, 1);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}


void Drive::setSpeed(int xAxis, int yAxis){
  printf("x: %i\n", xAxis);
  printf("y: %i\n", yAxis);
    
  // Y-axis used for forward and backward control
  if (yAxis < 0) {
    // Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    motorSpeedA = map(yAxis*-1, 0, 100, 0, 255);
    motorSpeedB = map(yAxis*-1, 0, 100, 0, 255);
  }
  else if (yAxis >= 0) {
    // Set Motor A forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    motorSpeedA = map(yAxis, 0, 100, 0, 255);
    motorSpeedB = map(yAxis, 0, 100, 0, 255);
  }
  // If joystick stays in middle the motors are not moving
  else {
    motorSpeedA = 0;
    motorSpeedB = 0;
  }
  // X-axis used for left and right control
  if (xAxis < 0) {
    // Convert the declining X-axis readings from 470 to 0 into increasing 0 to 255 value
    int xMapped = map(xAxis*-1, 0, 100, 0, 255);
    // Move to left - decrease left motor speed, increase right motor speed
    motorSpeedA = motorSpeedA - xMapped;
    motorSpeedB = motorSpeedB + xMapped;
    // Confine the range from 0 to 255
    if (motorSpeedA < 0) {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255) {
      motorSpeedB = 255;
    }
  }
  if (xAxis >= 0 ) {
   // Convert the increasing X-axis readings from 550 to 1023 into 0 to 255 value
   int xMapped = map(xAxis, 0, 100, 0, 255);
  // Move right - decrease right motor speed, increase left motor speed
    motorSpeedA = motorSpeedA + xMapped;
    motorSpeedB = motorSpeedB - xMapped;
  // Confine the range from 0 to 255
    if (motorSpeedA > 255) {
      motorSpeedA = 255;
    }
    if (motorSpeedB < 0) {
      motorSpeedB = 0;
    }
  }
// Prevent buzzing at low speeds (Adjust according to your motors. My motors couldn't start moving if PWM value was below value of 70)
  if (motorSpeedA < 70) {
    motorSpeedA = 0;
  }
  if (motorSpeedB < 70) {
    motorSpeedB = 0;
  }
  printf("left speed: %i\n", motorSpeedA);
  printf("right speed: %i\n", motorSpeedB);

  ledcWrite(0, motorSpeedA);
  ledcWrite(1, motorSpeedB);
}