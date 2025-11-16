#pragma once
#include "InformationReader.h"

class RfidReader : public InformationReader {
private:
    double frequency; // ????. 13.56 (MHz)

public:
    RfidReader(const std::string& model, const std::string& connection, double freq);
    ~RfidReader();

    void displayInfo() const override;
    void performScan() override;
};