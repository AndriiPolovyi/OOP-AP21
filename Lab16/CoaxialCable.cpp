#include "CoaxialCable.h"

CoaxialCable::CoaxialCable(double imp, double dia, double len)
    : impedance(imp), diameter(dia), length(len) {
    std::cout << "[KONSTRUKTOR]: Ob'yekt kabelyu stvoreno (Opir: " << impedance << " Om)\n";
}

CoaxialCable::~CoaxialCable() {
    std::cout << "[DESTRUKTOR]: Ob'yekt kabelyu vydaleno z pam'yati.\n";
}

void CoaxialCable::displayInfo() const {
    std::cout << "Kabelj -> Opir: " << impedance << " Om, Diametr: " << diameter
        << " mm, Dovzhyna: " << length << " m\n";
}

void CoaxialCable::transmitSignal() const {
    std::cout << ">>> Syhnal peredayetjsya po kabelyu dovzhynoyu " << length << " m...\n";
}