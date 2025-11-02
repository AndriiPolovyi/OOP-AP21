#ifndef COAXIAL_H
#define COAXIAL_H

#include <array>
#include <string>
#include <iostream>

const std::size_t MAX_RECORDS = 5;

struct Coax_t {
    int id;
    double Z;               // хвильовий опір (Ом)
    double D;               // діаметр (мм)
    double L;               // довжина (м)
};

class CoaxialManager {
private:
    std::array<Coax_t, MAX_RECORDS> records;

    bool isValidZ(double z) const;
    bool isValidD(double d) const;
    bool isValidL(double l) const;

public:
    CoaxialManager();                // конструктор
    ~CoaxialManager();               // деструктор

    void inputRecord(std::size_t index);
    void printRecord(std::size_t index) const;
    void printAll() const;
    void clearRecord(std::size_t index);
    bool setRecord(std::size_t index, const Coax_t& r);
    std::size_t capacity() const { return MAX_RECORDS; }
};

#endif 


