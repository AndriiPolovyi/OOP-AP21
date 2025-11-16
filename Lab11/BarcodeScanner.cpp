#include "BarcodeScanner.h"

BarcodeScanner::BarcodeScanner(const std::string& model, const std::string& connection, const std::string& tech)
    : InformationReader(model, connection), scanTechnology(tech) {
}

void BarcodeScanner::displayInfo() const {
    InformationReader::displayInfo(); 

    std::cout << ", Tekhnolohiya: " << scanTechnology << std::endl;
}