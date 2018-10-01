#include <Arduino.h>

#include "Drive.h"
#include "BLEDriveCallback.h"
#include "BLEConnection.h"

#define in1 2
#define in2 0
#define in3 4
#define in4 16
#define motorPin1 33
#define motorPin2 25

Drive* drive;

void setup() {

  Serial.begin(115200);

  drive = new Drive(in1, in2, in3, in4, motorPin1, motorPin2);

  BLEConnection* bleConn = new BLEConnection("QM-Bot");
  bleConn->setupDrive(drive);
  bleConn->start();

  Serial.println("Waiting a client connection to notify...");
}

void loop() {
}