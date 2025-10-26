#include <iostream>
#include "Cable.h" 

void showMenu() {
    std::cout << "\n====== MENU ======\n";
    std::cout << "1. Dodaty kabel\n";
    std::cout << "2. Pokazaty vsi kabeli\n";
    std::cout << "3. Vydalyty kabel\n";
    std::cout << "4. Vykhid\n";
    std::cout << "Vash vybir: ";
}

int main() {
    CableInventory inventory;
    int choice;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            inventory.addCable();
            break;
        case 2:
            inventory.displayCables();
            break;
        case 3:
            inventory.removeCable();
            break;
        case 0:
            std::cout << "Zavershennia roboty...\n";
            break;
        default:
            std::cout << "POMYLKA: Nevirnyi vybir. Sprobaite 1, 2, 3 abo 0.\n";

            std::cin.clear();
            std::cin.ignore(10000, '\n');
            break;
        }
    } while (choice != 0);

    return 0;
}