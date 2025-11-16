#pragma once
class InformationReader;
class BarcodeScanner;
class RFIDReader;
class DeviceTester {
public:
    
    void runDiagnostics(InformationReader& reader);
};