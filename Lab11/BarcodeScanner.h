#pragma once
#include "InformationReader.h"

class BarcodeScanner : public InformationReader {
protected:
    
    std::string scanTechnology; 

public:
    BarcodeScanner(const std::string& model, const std::string& connection, const std::string& tech);
    void displayInfo() const override;

    friend class DeviceTester;
};