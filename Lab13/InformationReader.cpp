#include "InformationReader.h"

InformationReader::InformationReader(const std::string& model, const std::string& conn)
    : modelName(model), connectionType(conn) {
}

void InformationReader::display() const {
    std::cout << "Modelj: " << modelName << ", Pidklyuchennya: " << connectionType;
}