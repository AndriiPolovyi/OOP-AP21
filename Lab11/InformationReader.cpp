#include "InformationReader.h"

InformationReader::InformationReader(const std::string& model, const std::string& connection)
    : modelName(model), connectionType(connection) {
    
}

void InformationReader::displayInfo() const {
    
    std::cout << "Modelj: " << modelName << ", Pidklyuchennya: " << connectionType;
}