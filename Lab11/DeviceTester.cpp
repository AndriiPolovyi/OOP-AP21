#include "DeviceTester.h"
#include "BarcodeScanner.h"
#include "RFIDReader.h"
#include <iostream>

void DeviceTester::runDiagnostics(InformationReader& reader) {
    std::cout << "\n--- Zapusk diahnostyky ---" << std::endl;
    BarcodeScanner* scanner = dynamic_cast<BarcodeScanner*>(&reader);
    if (scanner) {
        std::cout << "Testuvannya skanera..." << std::endl;
        std::cout << "[DRUZHNIY DOSTUP] Tech: " << scanner->scanTechnology << std::endl;
        std::cout << "Status: OK" << std::endl;
        return;
    }
    RFIDReader* rfid = dynamic_cast<RFIDReader*>(&reader);
    if (rfid) {
        std::cout << "Testuvannya RFID..." << std::endl;
        std::cout << "[DRUZHNIY DOSTUP] Freq: " << rfid->frequency << std::endl;
        std::cout << "Status: OK" << std::endl;
        return;
    }
}

void DeviceTester::calculateTotals(const std::vector<std::unique_ptr<InformationReader>>& devices) {
    double totalSum = 0.0;
    int count = 0;

    std::cout << "\n--- Finansovyy Zvit (Friend Class) ---" << std::endl;

    for (const auto& device : devices) {
        totalSum += device->price;
        count++;
    }

    std::cout << "Kilkistj prystroyiv: " << count << std::endl;
    std::cout << "Zahalna vartistj: " << totalSum << " UAH" << std::endl;

    if (count > 0) {
        std::cout << "Serednya vartistj: " << (totalSum / count) << " UAH" << std::endl;
    }
}