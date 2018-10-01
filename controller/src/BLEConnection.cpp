#include "BLEConnection.h"
#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" // UART service UUID
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

BLEConnection::BLEConnection(std::string deviceName){
    BLEDevice::init(deviceName); 

    pServer = BLEDevice::createServer();
    pService = pServer->createService(SERVICE_UUID);

}

void BLEConnection::start(){
    pService->start();

    pServer->getAdvertising()->start();
}

void BLEConnection::setupDrive(Drive* drive){
    BLECharacteristic* pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID_TX,
                      BLECharacteristic::PROPERTY_NOTIFY
                    );
                      
    pCharacteristic->addDescriptor(new BLE2902());

    pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID_RX,
                                         BLECharacteristic::PROPERTY_WRITE
                                       );
    
    pCharacteristic->setCallbacks(new BLEDriveCallback(drive));
}
