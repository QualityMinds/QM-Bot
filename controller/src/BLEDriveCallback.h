#ifndef BLEDriveCallback_H
#define BLEDriveCallback_H

#include <BLEServer.h>
#include "Drive.h"

class BLEDriveCallback: public BLECharacteristicCallbacks {
    public:
        BLEDriveCallback(Drive* _drive);
        void onWrite(BLECharacteristic *pCharacteristic);

    private:
        Drive* drive;
};
#endif