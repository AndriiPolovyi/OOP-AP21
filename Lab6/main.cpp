#include <iostream>
#include "coaxial.h"

int main() {
    CoaxialManager mgr;
    bool running = true;

    while (running) {
        std::cout << "\nMenu:\n"
            << "1 - Vvesty/redaguvaty zapis\n"
            << "2 - Vydalyty zapis\n"
            << "3 - Pokazaty vsi zapysy\n"
            << "4 - Zapovnyty pryklad testovykh danykh\n"
            << "5 - Vykhid\n"
            << "Oberit diyu: ";
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Nepravylnе vvedennya.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            std::cout << "Vkazhit indeks zapysu (0.." << mgr.capacity() - 1 << "): ";
            std::size_t idx; std::cin >> idx;
            mgr.inputRecord(idx);
            break;
        }
        case 2: {
            std::cout << "Vkazhit indeks dlya vydalennya (0.." << mgr.capacity() - 1 << "): ";
            std::size_t idx; std::cin >> idx;
            mgr.clearRecord(idx);
            break;
        }
        case 3:
            mgr.printAll();
            break;
        case 4: {
            Coax_t a{ 1, 50.0, 5.0, 10.0 };
            Coax_t b{ 2, 75.0, 8.5, 25.0 };
            Coax_t c{ 3, 50.0, 7.2, 100.0 };
            mgr.setRecord(0, a);
            mgr.setRecord(1, b);
            mgr.setRecord(2, c);
            std::cout << "Testovi dani dodano u sloty 0..2\n";
            break;
        }
        case 5:
            running = false;
            break;
        default:
            std::cout << "Nepravylnyi vybir.\n";
        }
    }

    std::cout << "Prohrama zavershena.\n";
    return 0;
}
