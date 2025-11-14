#include "barcode.h"

BarcodeScanner::BarcodeScanner(std::string model, double price, int speed)
    : Reader(model, price), scanSpeed(speed) {
}

BarcodeScanner::~BarcodeScanner() {
    std::cout << "Destroyed BarcodeScanner: " << model << "\n";
}

void BarcodeScanner::input() {
    Reader::input();
    std::cout << "Enter scan speed (scans/sec): ";
    std::cin >> scanSpeed;
    if (scanSpeed < 0) {
        std::cout << "Invalid speed, set to 0.\n";
        scanSpeed = 0;
    }
}

void BarcodeScanner::print() const {
    std::cout << "Type: Barcode Scanner\n";
    Reader::print();
    std::cout << "Scan speed: " << scanSpeed << " scans/sec\n";
}

std::string BarcodeScanner::getType() const {
    return "Barcode Scanner";
}
