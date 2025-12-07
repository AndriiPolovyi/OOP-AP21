#pragma once
#include <iostream>
#include <iomanip>

struct CoaxialCable {
    double impedance; 
    double diameter;  
    double length;    

    CoaxialCable(double imp = 0, double dia = 0, double len = 0)
        : impedance(imp), diameter(dia), length(len) {
    }

    friend std::ostream& operator<<(std::ostream& os, const CoaxialCable& cable) {
        os << "Opir: " << std::setw(3) << cable.impedance << " Om | "
            << "Diametr: " << std::setw(4) << cable.diameter << " mm | "
            << "Dovzhyna: " << std::setw(5) << cable.length << " m";
        return os;
    }

    bool operator==(const CoaxialCable& other) const {
        return (impedance == other.impedance &&
            diameter == other.diameter &&
            length == other.length);
    }
};