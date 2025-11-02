#pragma once
#include <iostream>
#include <string>

class CoaxialCable {
private:

    double waveImpedance; // Хвильовий опір
    double diameter;      // Діаметр
    double length;        // Довжина

    bool isValid(double val, const std::string& paramName);

public:
    
    CoaxialCable();

    CoaxialCable(double impedance, double diam, double len);

    ~CoaxialCable();

    void displayInfo() const;

    void setWaveImpedance(double newImpedance);
    void setDiameter(double newDiameter);
    void setLength(double newLength);

    double getLength() const;
    double getDiameter() const;
    double getWaveImpedance() const;
};