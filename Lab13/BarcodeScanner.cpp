#include "BarcodeScanner.h"
#include <stdexcept> 

BarcodeScanner::BarcodeScanner(const std::string& model, const std::string& conn, const std::string& tech)
    : InformationReader(model, conn), technology(tech) {
}

void BarcodeScanner::display() const {
    InformationReader::display();
    std::cout << ", Tekhnolohiya: " << technology << std::endl;
}

void BarcodeScanner::saveToFile(std::ofstream& out) const {
  
    out << getTypeID() << " " << modelName << " " << connectionType << " " << technology << std::endl;
}

void BarcodeScanner::loadFromFile(std::ifstream& in) {
    
    if (!(in >> modelName >> connectionType >> technology)) {
        throw std::runtime_error("Pomylka zchytuvannya danykh dlya BarcodeScanner");
    }
}