#pragma once
#include <iostream>
#include <string>

template <typename T>
class CoaxialCable {
private:
    T impedance;
    T diameter;
    T length;

public:
    CoaxialCable(T imp, T dia, T len) : impedance(imp), diameter(dia), length(len) {}

    void displayInfo() const {
        std::cout << "[ZAHAL'NYY SHABLON]: Opir: " << impedance
            << " Om, Diametr: " << diameter
            << " mm, Dovzhyna: " << length << " m\n";
    }
};

template <typename T>
class CoaxialCable<T*> {
private:
    T* impedance;
    T* diameter;
    T* length;

public:
    CoaxialCable(T* imp, T* dia, T* len) : impedance(imp), diameter(dia), length(len) {}

    void displayInfo() const {
        std::cout << "[CHASTKOVA SPETSIALIZATSIYA (Vkazivnyky)]: Opir: " << *impedance
            << " Om, Diametr: " << *diameter
            << " mm, Dovzhyna: " << *length << " m\n";
    }
};

template <>
class CoaxialCable<std::string> {
private:
    std::string impedance;
    std::string diameter;
    std::string length;

public:
    CoaxialCable(std::string imp, std::string dia, std::string len)
        : impedance(imp), diameter(dia), length(len) {
    }

    void displayInfo() const {
        std::cout << "[POVNA SPETSIALIZATSIYA (String)]: Opir: " << impedance
            << ", Diametr: " << diameter
            << ", Dovzhyna: " << length << "\n";
    }
};