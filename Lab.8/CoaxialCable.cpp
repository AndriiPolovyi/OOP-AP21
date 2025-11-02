#include "CoaxialCable.h"
#include <iostream>
#include <iomanip> 

CoaxialCable::CoaxialCable() {
    waveImpedance = 50.0; 
    diameter = 5.0;
    length = 1.0;
    std::cout << "LOG: Vyklikano konstruktor za zamovchuvanniam.\n";
}

CoaxialCable::CoaxialCable(double impedance, double diam, double len) {
   
    setWaveImpedance(impedance);
    setDiameter(diam);
    setLength(len);
    std::cout << "LOG: Vyklikano konstruktor z parametramy.\n";
}

CoaxialCable::~CoaxialCable() {
    std::cout << "LOG: Vyklikano destruktor dlia kabeliu ("
        << waveImpedance << " Om).\n";
}

bool CoaxialCable::isValid(double val, const std::string& paramName) {
    if (val > 0) {
        return true;
    }
    std::cout << "POMYLKA: '" << paramName << "' maie buty bilshe 0. "
        << "Znachennia " << val << " ne vstanovleno.\n";
    return false;
}

void CoaxialCable::displayInfo() const {
    std::cout << std::fixed << std::setprecision(2) 
        << "  > Kabel: Opir: " << waveImpedance << " Om, "
        << "Diametr: " << diameter << " mm, "
        << "Dovzhyna: " << length << " m.\n";
}

void CoaxialCable::setWaveImpedance(double newImpedance) {
    if (isValid(newImpedance, "Khvyliovyi Opir")) {
        waveImpedance = newImpedance;
    }
}

void CoaxialCable::setDiameter(double newDiameter) {
    if (isValid(newDiameter, "Diametr")) {
        diameter = newDiameter;
    }
}

void CoaxialCable::setLength(double newLength) {
    if (isValid(newLength, "Dovzhyna")) {
        length = newLength;
    }
}

double CoaxialCable::getLength() const {
    return length;
}
double CoaxialCable::getDiameter() const {
    return diameter;
}
double CoaxialCable::getWaveImpedance() const {
    return waveImpedance;
}