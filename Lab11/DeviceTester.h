#pragma once
#include <vector>
#include <memory>
#include "InformationReader.h" 

class BarcodeScanner;
class RFIDReader;

class DeviceTester {
public:
    void runDiagnostics(InformationReader& reader);

    void calculateTotals(const std::vector<std::unique_ptr<InformationReader>>& devices);
};