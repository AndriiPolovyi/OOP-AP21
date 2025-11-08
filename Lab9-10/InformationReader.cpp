#include "InformationReader.h"
#include <iostream>

// ???????????
InformationReader::InformationReader(const std::string& model, const std::string& connection)
    : modelName("Unknown"), connectionType("Wired") {

    // ?????????
    if (!model.empty()) {
        modelName = model;
    }
    else {
        std::cout << "POMYLKA: Nazva modeli ne mozhe buty porozhnoiu.\n";
    }

    setConnectionType(connection);
}

InformationReader::~InformationReader() {
    std::cout << "LOG: Vyklykano VIRTUALNYI destruktor InformationReader dlia '"
        << modelName << "'...\n";
}

void InformationReader::displayInfo() const {
    std::cout << "Model: " << modelName << "\n";
    std::cout << "  Typ pidkliuchennia: " << connectionType << "\n";
}

void InformationReader::setConnectionType(const std::string& connection) {
    if (connection == "USB" || connection == "Bluetooth" || connection == "Wi-Fi" || connection == "Wired") {
        connectionType = connection;
    }
    else {
        std::cout << "POMYLKA: Nevirnyi typ pidkliuchennia '" << connection
            << "'. Vstanovleno 'Wired'.\n";
        connectionType = "Wired";
    }
}