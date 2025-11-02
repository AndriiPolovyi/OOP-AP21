#include "Cable.h"
#include <iostream>
#include <iomanip>    
#include <limits>     
#include <algorithm> 

Cable::Cable() {
    std::cout << "-> Stvoreno inventar kabeliv.\n";
}

Cable::~Cable() {
    std::cout << "-> Inventar ochyshcheno, pamiat zvilneno.\n";
}

bool Cable::validateInput(double impedance, double diameter, double length) {
    if (impedance <= 0 || diameter <= 0 || length <= 0) {
        std::cout << "POMYLKA: Vsi znachennia (opir, diametr, dovzhyna) maiut buty > 0.\n";
        return false;
    }
    return true;
}

int Cable::getIndexInput(const std::string& prompt) {
    int index;
    while (true) {
        std::cout << prompt;
        if (std::cin >> index) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return index;
        }
        else {
            
            std::cout << "POMYLKA: Vvedit chyslo.\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
    }
}

void Cable::addCable() {
    CoaxCable_t newCable;

    std::cout << "\n--- Dodavannia kabeliu (v kinets) ---\n";
    std::cout << "Vvedit khvyliovyi opir (Om): ";
    std::cin >> newCable.impedance;
    std::cout << "Vvedit diametr (mm): ";
    std::cin >> newCable.diameter;
    std::cout << "Vvedit dovzhynu (m): ";
    std::cin >> newCable.length;
  
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (validateInput(newCable.impedance, newCable.diameter, newCable.length)) {
        cables.push_back(newCable);
        std::cout << "-> Kabel uspishno dodano!\n";
    }
    else {
        std::cout << "-> Kabel ne dodano cherez nevirni dani.\n";
    }
}

void Cable::insertCable() {
    std::cout << "\n--- Vstavka kabeliu (za indeksom) ---\n";
    int index = getIndexInput("Vvedit indeks dlia vstavky (0..." + std::to_string(cables.size()) + "): ");
    if (index < 0 || index > cables.size()) {
        std::cout << "POMYLKA: Nevirnyi indeks. Dozvoleno vid 0 do " << cables.size() << ".\n";
        return;
    }

    CoaxCable_t newCable;
    std::cout << "Vvedit khvyliovyi opir (Om): ";
    std::cin >> newCable.impedance;
    std::cout << "Vvedit diametr (mm): ";
    std::cin >> newCable.diameter;
    std::cout << "Vvedit dovzhynu (m): ";
    std::cin >> newCable.length;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (validateInput(newCable.impedance, newCable.diameter, newCable.length)) {
        cables.insert(cables.begin() + index, newCable); 
        std::cout << "-> Kabel uspishno vstavleno na pozytsiiu " << index << "!\n";
    }
    else {
        std::cout << "-> Kabel ne vstavleno cherez nevirni dani.\n";
    }
}

void Cable::removeCable() {
    std::cout << "\n--- Vydalennia kabeliu ---\n";
    if (cables.empty()) {
        std::cout << "-> Inventar vzhe porozhnii.\n";
        return;
    }

    int index = getIndexInput("Vvedit indeks (N) kabeliu dlia vydalennia: ");

    if (index >= 0 && index < cables.size()) {
        cables.erase(cables.begin() + index); 
        std::cout << "-> Kabel " << index << " vydaleno.\n";
    }
    else {
        std::cout << "POMYLKA: Nevirnyi indeks! Ye lyshe vid 0 do " << cables.size() - 1 << ".\n";
    }
}

void Cable::swapCables() {
    std::cout << "\n--- Obmin kabeliv mistsiamy ---\n";
    if (cables.size() < 2) {
        std::cout << "-> Nedostatno kabeliv dlia obminu (potribno khocha b 2).\n";
        return;
    }

    int index1 = getIndexInput("Vvedit indeks pershoho kabeliu (0..." + std::to_string(cables.size() - 1) + "): ");
    int index2 = getIndexInput("Vvedit indeks druhoho kabeliu (0..." + std::to_string(cables.size() - 1) + "): ");

    if (index1 < 0 || index1 >= cables.size() || index2 < 0 || index2 >= cables.size()) {
        std::cout << "POMYLKA: Odyn abo obydva indeksy nevirni.\n";
        return;
    }

    if (index1 == index2) {
        std::cout << "-> Vy obraly odnakovykh indeksy. Obmin ne potriben.\n";
        return;
    }

    std::swap(cables[index1], cables[index2]);
    std::cout << "-> Kabeli " << index1 << " ta " << index2 << " uspishno pominialys mistsiamy.\n";
}

void Cable::clearInventory() {
    std::cout << "\n--- Ochyshchennia inventaria ---\n";
    if (cables.empty()) {
        std::cout << "-> Inventar vzhe porozhnii.\n";
        return;
    }

    cables.clear(); 
    std::cout << "-> Ves spysok kabeliv vydaleno.\n";
}

void Cable::displayCables() {
    std::cout << "\n--- SPYSOK KABELIV ---\n";

    if (cables.empty()) {
        std::cout << "Inventar porozhnii.\n";
        return;
    }

    std::cout << "-------------------------------------------------\n";
    std::cout << "| N | Opir (Om) | Diametr (mm) | Dovzhyna (m) |\n";
    std::cout << "-------------------------------------------------\n";

    std::cout << std::fixed << std::setprecision(2);

    for (size_t i = 0; i < cables.size(); ++i) {
        std::cout << "| " << std::setw(1) << i << " | "
            << std::setw(9) << cables[i].impedance << " | "
            << std::setw(12) << cables[i].diameter << " | "
            << std::setw(11) << cables[i].length << " |\n";
    }
    std::cout << "-------------------------------------------------\n";
    std::cout << "Vsoho: " << cables.size() << " sht.\n";
}