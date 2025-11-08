#include "BarcodeScanner.h"
#include <iostream>

// ?????? ???????????? ???????? ?????
BarcodeScanner::BarcodeScanner(const std::string& model,
    const std::string& connection,
    const std::string& tech)
    : InformationReader(model, connection), scanTechnology(tech) {
    std::cout << "LOG: Stvoreno BarcodeScanner.\n";
}

BarcodeScanner::~BarcodeScanner() {
    std::cout << "LOG: Destruktor BarcodeScanner dlia '" << modelName << "'...\n";
}

void BarcodeScanner::displayInfo() const {
    std::cout << "\n--- SKANER SHTRYKH-KODU --- \n";

    InformationReader::displayInfo();
    std::cout << "  Tekhnolohiia skanuvannia: " << scanTechnology << "\n";
}

void BarcodeScanner::performScan() {
    std::cout << "  SKANUIU: *Bip-bip!* Skanovano 1D/2D shtrykh-kod.\n";
}