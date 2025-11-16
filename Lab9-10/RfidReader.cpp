#include "RfidReader.h"
#include <iostream>
#include <iomanip> // Для setprecision

// Виклик конструктора базового класу
RfidReader::RfidReader(const std::string& model, const std::string& connection, double freq)
    : InformationReader(model, connection), frequency(13.56) {

    // Валідація
    if (freq > 0) {
        frequency = freq;
    }
    else {
        std::cout << "POMYLKA: Chastota maie buty > 0.\n";
    }
    std::cout << "LOG: Stvoreno RfidReader.\n";
}

RfidReader::~RfidReader() {
    std::cout << "LOG: Destruktor RfidReader dlia '" << modelName << "'...\n";
}

// Перевизначена функція
void RfidReader::displayInfo() const {
    std::cout << "\n--- RFID ZCHYTUVACH --- \n";
    // Виклик базової версії функції
    InformationReader::displayInfo();
    std::cout << std::fixed << std::setprecision(2)
        << "  Robocha chastota: " << frequency << " MHz\n";
}

// Перевизначена функція
void RfidReader::performScan() {
    std::cout << "  SKANUIU: *Bzzt!* Zchytano RFID-mitku.\n";
}
