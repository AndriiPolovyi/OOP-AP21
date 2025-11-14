#include <iostream>
#include <vector>
#include "InformationReader.h" 
#include "BarcodeScanner.h"    
#include "RfidReader.h"

int main() {
    std::vector<InformationReader*> deviceList;

    std::cout << "Stvorennia ob'iektiv...\n";

    deviceList.push_back(new BarcodeScanner("Zebra DS2208", "USB", "LED"));
    deviceList.push_back(new RfidReader("NFC-PM5", "Bluetooth", 13.56));
    deviceList.push_back(new BarcodeScanner("Honeywell 1900", "Wi-Fi", "Laser"));

    std::cout << "\n--- Demonstratsiia POLIMORFIZMU ---\n";
    std::cout << "Vyvolaemo virtualni funktsii v tsykli,\n";
    std::cout << "ne znaiuchy pro konkretnyi typ ob'iekta:\n";

    for (InformationReader* device : deviceList) {
    
        device->displayInfo();
        device->performScan();
    }

    std::cout << "\n--- Ochyshchennia pamiati ---\n";

    for (InformationReader* device : deviceList) {
        delete device; 
    }
    deviceList.clear(); 

    std::cout << "Prohrama zavershena.\n";
    return 0;
}