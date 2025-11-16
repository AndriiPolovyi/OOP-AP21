#include <iostream>
#include <vector>
#include <memory> 

#include "InformationReader.h"
#include "BarcodeScanner.h"
#include "RFIDReader.h"
#include "DeviceTester.h"

int main() {
   
    std::vector<std::unique_ptr<InformationReader>> devices;

    devices.push_back(std::make_unique<BarcodeScanner>("Symbol LS2208", "USB", "Laser"));
    devices.push_back(std::make_unique<RFIDReader>("Zebra RFD8500", "Bluetooth", "UHF", 6.0));
    devices.push_back(std::make_unique<BarcodeScanner>("Datalogic QD2430", "USB", "2D Imager"));

    std::cout << "--- Perelik prystroyiv ---" << std::endl;
    for (const auto& device : devices) {
        device->displayInfo(); 
    }

    DeviceTester tester;

    std::cout << "\n--- Zapusk testiv druzhnim klasom ---" << std::endl;
    for (const auto& device : devices) {
        tester.runDiagnostics(*device); 
    }

    return 0;
}