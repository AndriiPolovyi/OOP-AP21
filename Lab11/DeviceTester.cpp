#include "DeviceTester.h"
#include "BarcodeScanner.h" 
#include "RFIDReader.h"
#include <iostream>

void DeviceTester::runDiagnostics(InformationReader& reader) {
    std::cout << "\n--- Zapusk diahnostyky ---" << std::endl;

    BarcodeScanner* scanner = dynamic_cast<BarcodeScanner*>(&reader);
    if (scanner) {
        std::cout << "Testuvannya skanera shtrykh-kodu..." << std::endl;

        std::cout << "[DRUZHNIY DOSTUP] Dostup do zakhyshchenoyi tekhnolohiyi: " << scanner->scanTechnology << std::endl;
        std::cout << "Test: OK" << std::endl;
        return;
    }

    RFIDReader* rfid = dynamic_cast<RFIDReader*>(&reader);
    if (rfid) {
        std::cout << "Testuvannya RFID-zchytuvacha..." << std::endl;

        std::cout << "[DRUZHNIY DOSTUP] Dostup do zakhyshchenoyi chastoty: " << rfid->frequency << std::endl;
        std::cout << "[DRUZHNIY DOSTUP] Dostup do zakhyshchenoyi dystantsiyi: " << rfid->readRange_m << "m" << std::endl;
        std::cout << "Test: OK" << std::endl;
        return;
    }

    std::cout << "Nevidomyy typ prystroyu. Nemozhlyvo zapustyty diahnostyku." << std::endl;
}