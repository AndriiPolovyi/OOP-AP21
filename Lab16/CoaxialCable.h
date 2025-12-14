#pragma once
#include <string>
#include <iostream>

class CoaxialCable {
private:
    double impedance;
    double diameter;
    double length;

public:
    CoaxialCable(double imp, double dia, double len);

    ~CoaxialCable();

    void displayInfo() const;

    void transmitSignal() const;
};