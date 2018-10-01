#include "BLEDriveCallback.h"

    BLEDriveCallback::BLEDriveCallback(Drive* _drive){
        drive = _drive;
    }

    void BLEDriveCallback::onWrite(BLECharacteristic *pCharacteristic) {
      std::string rxValue = pCharacteristic->getValue();

      if (rxValue.length() > 0) {

        const char* test = rxValue.c_str();
        char* test2 = strdup(test);
        char* delim = ":";
        char* splits = strtok(test2, delim);

        int x = (int) strtol(splits, NULL, 10);
	      splits = strtok(NULL, delim);
        int y = (int) strtol(splits, NULL, 10);

        drive->setSpeed(x, y);
      }
    }
