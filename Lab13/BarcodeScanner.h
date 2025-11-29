#pragma once
#include "InformationReader.h"

class BarcodeScanner : public InformationReader {
private:
    std::string technology; 

public:
    BarcodeScanner(const std::string& model = "", const std::string& conn = "", const std::string& tech = "");

    void display() const override;
    void saveToFile(std::ofstream& out) const override;
    void loadFromFile(std::ifstream& in) override;
    int getTypeID() const override { return 1; } 
};