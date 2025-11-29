#pragma once
#include "InformationReader.h"

class RFIDReader : public InformationReader {
private:
    std::string frequency; 
    double range;          

public:
    RFIDReader(const std::string& model = "", const std::string& conn = "", const std::string& freq = "", double r = 0.0);

    void display() const override;
    void saveToFile(std::ofstream& out) const override;
    void loadFromFile(std::ifstream& in) override;
    int getTypeID() const override { return 2; } 
};