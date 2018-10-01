#ifndef BLEConnection_H
#define BLEConnection_H
#include <sstream>

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include "Drive.h"
#include "BLEDriveCallback.h"

class BLEConnection{
    public:
        BLEConnection(std::string deviceName);
        void setupDrive(Drive* drive);
        void start();
    private:
        BLEServer *pServer;
        BLEService *pService;
 };
#endif