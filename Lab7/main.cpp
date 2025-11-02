#include <iostream>
#include <limits> 
#include "Cable.h" 

void showMenu() {
    std::cout << "\n============= MENU INVENTARIA ============\n";
    std::cout << "1. Dodaty kabel (v kinets)\n";
    std::cout << "2. Vstavyty kabel (za indeksom)\n";
    std::cout << "3. Vydalyty kabel (za indeksom)\n";
    std::cout << "4. Pominiaty 2 kabeli mistsiamy\n";
    std::cout << "5. Ochystyty ves spysok\n";
    std::cout << "6. Pokazaty vsi kabeli\n";
    std::cout << "0. Vykhid\n"; 
    std::cout << "===========================================\n";
    std::cout << "Vash vybir: ";
}

int main() {
    Cable inventory; 
    int choice;

    do {
        showMenu();

        if (!(std::cin >> choice)) {
            std::cout << "POMYLKA: Vvedit chyslo vid 0 do 6.\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            inventory.addCable();
            break;
        case 2:
            inventory.insertCable();
            break;
        case 3:
            inventory.removeCable();
            break;
        case 4:
            inventory.swapCables();
            break;
        case 5:
            inventory.clearInventory();
            break;
        case 6:
            inventory.displayCables();
            break;
        case 0:
            std::cout << "Zavershennia roboty...\n";
            break;
        default:
            std::cout << "POMYLKA: Nevirnyi vybir. Sprobaite vid 0 do 6.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}