#include <iostream>
#include "LinkedList.h"

void showMenu() {
    std::cout << "\n=== MENYU KERUVANNYA SPYSKOM (Variant 13: Koaksial'nyy kabel') ===\n";
    std::cout << "1. Dodaty kabel' na pochatok\n";
    std::cout << "2. Dodaty kabel' v kinetsj\n";
    std::cout << "3. Vydalyty z pochatku\n";
    std::cout << "4. Vydalyty z kintsya\n";
    std::cout << "5. Pokazaty spysok\n";
    std::cout << "6. Sortuvaty za dovzhynoyu\n";
    std::cout << "7. Ochystyty spysok\n";
    std::cout << "0. Vykhid\n";
    std::cout << "Vash vybir: ";
}

CoaxialCable inputCable() {
    double imp, dia, len;
    std::cout << "Vveditj Opir (Om): "; std::cin >> imp;
    std::cout << "Vveditj Diametr (mm): "; std::cin >> dia;
    std::cout << "Vveditj Dovzhynu (m): "; std::cin >> len;
    return CoaxialCable(imp, dia, len);
}

int main() {
    LinkedList list;
    int choice;

    list.pushBack(CoaxialCable(50, 6.5, 100.0));
    list.pushBack(CoaxialCable(75, 4.8, 50.5));
    list.pushBack(CoaxialCable(50, 9.0, 200.0));

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            list.pushFront(inputCable());
            break;
        case 2:
            list.pushBack(inputCable());
            break;
        case 3:
            list.popFront();
            break;
        case 4:
            list.popBack();
            break;
        case 5:
            list.printList();
            break;
        case 6:
            list.sortByLength();
            list.printList();
            break;
        case 7:
            list.clear();
            std::cout << ">>> Spysok ochyshcheno.\n";
            break;
        case 0:
            std::cout << "Robota zavershena.\n";
            break;
        default:
            std::cout << "Neâ³ðniy vybir, sprobuyte shche raz.\n";
        }
    } while (choice != 0);

    return 0;
}