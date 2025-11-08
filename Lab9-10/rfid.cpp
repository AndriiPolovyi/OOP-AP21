#include "rfid.h"

RFIDReader::RFIDReader(std::string model, double price, double range)
    : Reader(model, price), range(range) {
}

RFIDReader::~RFIDReader() {
    std::cout << "Destroyed RFIDReader: " << model << "\n";
}

void RFIDReader::input() {
    Reader::input();
    std::cout << "Enter read range (m): ";
    std::cin >> range;
    if (range < 0) {
        std::cout << "Invalid range, set to 0.\n";
        range = 0;
    }
}

void RFIDReader::print() const {
    std::cout << "Type: RFID Reader\n";
    Reader::print();
    std::cout << "Range: " << range << " m\n";
}

std::string RFIDReader::getType() const {
    return "RFID Reader";
}
