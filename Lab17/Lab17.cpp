#include <iostream>
#include "CoaxialCable.h"

int main() {
    std::cout << "=== LABORATORNA ROBOTA #17: SHABLONY KLASIV ===\n\n";

    std::cout << "1. Test zahal'noho shablonu (typ double):\n";
    CoaxialCable<double> cable1(50.5, 7.2, 100.0);
    cable1.displayInfo();

    std::cout << "\n2. Test chastkovoyi spetsializatsiyi (vkazivnyky):\n";
    int imp = 75, dia = 5, len = 250;
    CoaxialCable<int*> cable2(&imp, &dia, &len);
    cable2.displayInfo();

    std::cout << "\n3. Test povnoyi spetsializatsiyi (std::string):\n";
    CoaxialCable<std::string> cable3("Duzhe vysokyy", "Tonkyy", "Kratna 10");
    cable3.displayInfo();

    std::cout << "\nProhramu zaversheno uspishno.\n";
    return 0;
}