#include "RFIDReader.h"

RFIDReader::RFIDReader(const std::string& model, const std::string& connection, const std::string& freq, double range)
    : InformationReader(model, connection), frequency(freq), readRange_m(range) {
}

void RFIDReader::displayInfo() const {
    InformationReader::displayInfo(); 

    std::cout << ", Chastota: " << frequency << ", Dystantsiya (m): " << readRange_m << std::endl;
}