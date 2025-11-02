#include <iostream>
#include "CoaxialCable.h"

void updateCableByReference(CoaxialCable& cable, double newImpedance, double newDiameter) {
    std::cout << "LOG: Funktsiia otrymala POSYLANNIA. Zminiuemo ob'iekt...\n";

    cable.setWaveImpedance(newImpedance);
    cable.setDiameter(newDiameter);

    std::cout << "LOG: Ob'iekt u funktsii onovleno.\n";
}

int main() {
    
    std::cout << "Stvorennia kabeliu 1 (cherez konstruktor z parametramy)\n";
    CoaxialCable cable1(75.0, 6.8, 100.0);

    std::cout << "Pochatkova informatsiia:\n";
    cable1.displayInfo();

    std::cout << "\nStvorennia kabeliu 2 (cherez konstruktor za zamovchuvanniam)\n";
    CoaxialCable cable2;

    std::cout << "Informatsiia za zamovchuvanniam:\n";
    cable2.displayInfo();

    std::cout << "\nVylyk settera dlia kabeliu 2...\n";
    cable2.setLength(25.5);
    std::cout << "Informatsiia pislia settera:\n";
    cable2.displayInfo();

    std::cout << "\nVylyk funktsii, shcho pryimaie POSYLANNIA (dlia cable1)...\n";
    updateCableByReference(cable1, 50.0, 10.2); 

    std::cout << "Onovlena informatsiia (pislia funktsii z posylanniam):\n";
    cable1.displayInfo(); 

    std::cout << "\nSproba vstanovyty nevirne znachennia dlia cable1...\n";
    cable1.setLength(-50.0); 
    std::cout << "Informatsiia pislia sproby nevirnoho vvodu:\n";
    cable1.displayInfo(); 

    std::cout << "\nZavershennia roboty. Vyklyk desktruktoriv...\n";
    return 0;
}