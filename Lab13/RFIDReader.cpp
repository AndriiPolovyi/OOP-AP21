#include "RFIDReader.h"
#include <stdexcept>

RFIDReader::RFIDReader(const std::string& model, const std::string& conn, const std::string& freq, double r)
    : InformationReader(model, conn), frequency(freq), range(r) {
}

void RFIDReader::display() const {
    InformationReader::display();
    std::cout << ", Chastota: " << frequency << ", Dystantsiya: " << range << " m" << std::endl;
}

void RFIDReader::saveToFile(std::ofstream& out) const {
    out << getTypeID() << " " << modelName << " " << connectionType << " " << frequency << " " << range << std::endl;
}

void RFIDReader::loadFromFile(std::ifstream& in) {
    if (!(in >> modelName >> connectionType >> frequency >> range)) {
        throw std::runtime_error("Pomylka zchytuvannya danykh dlya RFIDReader");
    }
}