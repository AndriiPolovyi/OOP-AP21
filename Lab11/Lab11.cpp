#include <iostream>
#include <vector>
#include <memory>

#include "InformationReader.h"
#include "BarcodeScanner.h"
#include "RFIDReader.h"
#include "DeviceTester.h"

int main() {
    std::vector<std::unique_ptr<InformationReader>> devices;

    devices.push_back(std::make_unique<BarcodeScanner>("Symbol LS2208", "USB", 3500.00, "Laser"));
    devices.push_back(std::make_unique<RFIDReader>("Zebra RFD8500", "Bluetooth", 12000.50, "UHF", 6.0));
    devices.push_back(std::make_unique<BarcodeScanner>("Datalogic QD2430", "USB", 4200.00, "2D Imager"));

    std::cout << "--- Inventaryzatsiya ---" << std::endl;
    for (const auto& device : devices) {
        device->displayInfo();
    }

    DeviceTester tester;

    for (const auto& device : devices) {
        tester.runDiagnostics(*device);
    }

    tester.calculateTotals(devices);

    return 0;
}