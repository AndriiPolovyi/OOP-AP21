#include "Cable.h" 
#include <iostream>
#include <iomanip> 

CableInventory::CableInventory() {
    std::cout << "-> Stvoreno inventar kabeliv.\n";
}

CableInventory::~CableInventory() {
    std::cout << "-> Inventar ochyshcheno, pamiat zvilneno.\n";
}

bool CableInventory::validateInput(double impedance, double diameter, double length) {
    if (impedance <= 0 || diameter <= 0 || length <= 0) {
        std::cout << "POMYLKA: Vsi znachennia (opir, diametr, dovzhyna) maiut buty > 0.\n";
        return false;
    }
    return true;
}

void CableInventory::addCable() {
    CoaxCable_t newCable;

    std::cout << "Vvedit khvyliovyi opir (Om): ";
    std::cin >> newCable.impedance;
    std::cout << "Vvedit diametr (mm): ";
    std::cin >> newCable.diameter;
    std::cout << "Vvedit dovzhynu (m): ";
    std::cin >> newCable.length;

    if (validateInput(newCable.impedance, newCable.diameter, newCable.length)) {
        cables.push_back(newCable);
        std::cout << "-> Kabel uspishno dodano!\n";
    }
    else {
        std::cout << "-> Kabel ne dodano cherez nevirni dani.\n";
    }
}

void CableInventory::displayCables() {
    std::cout << "\n--- SPYSOK KABELIV ---\n";

    if (cables.empty()) {
        std::cout << "Inventar porozhnii.\n";
        return;
    }

    std::cout << "-------------------------------------------------\n";
    std::cout << "| N | Opir (Om) | Diametr (mm) | Dovzhyna (m) |\n";
    std::cout << "-------------------------------------------------\n";

    for (size_t i = 0; i < cables.size(); ++i) {
        std::cout << "| " << std::setw(1) << i << " | "
            << std::setw(9) << cables[i].impedance << " | "
            << std::setw(12) << cables[i].diameter << " | "
            << std::setw(11) << cables[i].length << " |\n";
    }
    std::cout << "-------------------------------------------------\n";
    std::cout << "Vsoho: " << cables.size() << " sht.\n";
}

void CableInventory::removeCable() {
    if (cables.empty()) {
        std::cout << "-> Inventar vzhe porozhnii.\n";
        return;
    }

    int index;
    std::cout << "Vvedit nomer (N) kabeliu dlia vydalennia: ";
    std::cin >> index;

    // Perevirka indeksu
    if (index >= 0 && index < cables.size()) {
        cables.erase(cables.begin() + index);
        std::cout << "-> Kabel " << index << " vydaleno.\n";
    }
    else {
        std::cout << "POMYLKA: Nevirnyi nomer! Ye lyshe vid 0 do " << cables.size() - 1 << ".\n";
    }
}