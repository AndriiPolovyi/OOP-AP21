#pragma once
#include "InformationReader.h"

class RFIDReader : public InformationReader {
protected:
    std::string frequency;
    double readRange_m;

public:
    RFIDReader(const std::string& model, const std::string& connection, double cost, const std::string& freq, double range);

    void displayInfo() const override;

    friend class DeviceTester;
};