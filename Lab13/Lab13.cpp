#include <iostream>
#include <vector>
#include <fstream>
#include <memory>     
#include <stdexcept> 

#include "InformationReader.h"
#include "BarcodeScanner.h"
#include "RFIDReader.h"

void saveData(const std::string& filename, const std::vector<std::unique_ptr<InformationReader>>& devices) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw std::runtime_error("Nemozhlyvo vidkryty fayl dlya zapysu: " + filename);
    }

    for (const auto& dev : devices) {
        dev->saveToFile(outFile);
    }
    outFile.close();
    std::cout << ">>> Dani uspishno zberezheno u fayl " << filename << std::endl;
}

void loadData(const std::string& filename, std::vector<std::unique_ptr<InformationReader>>& devices) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        throw std::runtime_error("Nemozhlyvo vidkryty fayl dlya chytannya: " + filename);
    }

    std::cout << ">>> Pochynayemo zchytuvannya z faylu..." << std::endl;

    int typeId;

    while (inFile >> typeId) {
        std::unique_ptr<InformationReader> newDevice;

        if (typeId == 1) {
            newDevice = std::make_unique<BarcodeScanner>();
        }
        else if (typeId == 2) {
            newDevice = std::make_unique<RFIDReader>();
        }
        else {
            throw std::runtime_error("Nevidomyy typ prystroyu u fayli (ID: " + std::to_string(typeId) + ")");
        }

        newDevice->loadFromFile(inFile);
        devices.push_back(std::move(newDevice));
    }
    inFile.close();
    std::cout << ">>> Dani uspishno zavantazheno." << std::endl;
}

int main() {
    std::string filename = "devices_data.txt";
    std::vector<std::unique_ptr<InformationReader>> myDevices;

    try {
        std::cout << "--- Etap 1: Stvorennya danykh ta zapys ---" << std::endl;

        myDevices.push_back(std::make_unique<BarcodeScanner>("Symbol_LS2208", "USB", "Laser"));
        myDevices.push_back(std::make_unique<RFIDReader>("Zebra_RFD8500", "Bluetooth", "UHF", 6.5));
        myDevices.push_back(std::make_unique<BarcodeScanner>("Honeywell_1450g", "USB", "2D-Imager"));

        for (const auto& d : myDevices) d->display();

        saveData(filename, myDevices);

        std::cout << "\n--- Etap 2: Ochyshchennya pam'yati ta zchytuvannya ---" << std::endl;
        myDevices.clear(); 
        std::cout << "Pam'yatj ochyshcheno. Kilkistj elementiv: " << myDevices.size() << std::endl;

        loadData(filename, myDevices);

        std::cout << "\n--- Etap 3: Perevirka zchytanykh danykh ---" << std::endl;
        for (const auto& d : myDevices) {
            d->display();
        }

        std::cout << "\n--- Etap 4: Testuvannya pomylky (neisnuyuchyy fayl) ---" << std::endl;
        std::vector<std::unique_ptr<InformationReader>> emptyList;
        loadData("neisnuyuchyy_fayl.txt", emptyList);

    }
    catch (const std::exception& e) {
        
        std::cerr << "[VYNYATOK]: " << e.what() << std::endl;
    }

    return 0;
}