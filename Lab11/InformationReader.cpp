#include "InformationReader.h"

InformationReader::InformationReader(const std::string& model, const std::string& connection, double cost)
    : modelName(model), connectionType(connection), price(cost) {
}

void InformationReader::displayInfo() const {
    std::cout << "Modelj: " << modelName
        << ", Pidklyuchennya: " << connectionType
        << ", Tsina: " << price << " UAH"; // Vyvodymo tsinu
}