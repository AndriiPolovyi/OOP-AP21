#pragma once 
#include <iostream>
#include <vector>
#include <string>

struct CoaxCable_t {
    double impedance; // Хвильовий опір
    double diameter;  // Діаметр
    double length;    // Довжина
};

// Мій клас
class Cable {
private:
    std::vector<CoaxCable_t> cables;

    bool validateInput(double impedance, double diameter, double length);

    int getIndexInput(const std::string& prompt);

public:
    Cable(); 
    ~Cable(); 

    void addCable();        
    void insertCable();     
    void removeCable();     
    void swapCables();      
    void clearInventory();  
    void displayCables();   
};