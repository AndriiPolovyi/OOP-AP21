#pragma once
#include "InformationReader.h"

class BarcodeScanner : public InformationReader {
private:
    std::string scanTechnology;

public:
    BarcodeScanner(const std::string& model, const std::string& connection,
        const std::string& tech);

    ~BarcodeScanner();

    void displayInfo() const override;
    void performScan() override;
};