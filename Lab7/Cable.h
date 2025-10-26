#include <iostream>
#include <vector>  
#include <string>

struct CoaxCable_t {
    double impedance; // ????????? ????
    double diameter;  // ???????
    double length;    // ???????
};

class CableInventory {
private:

    std::vector<CoaxCable_t> cables;

    bool validateInput(double impedance, double diameter, double length);

public:
    CableInventory();
    ~CableInventory();

    void addCable();        // ??????
    void displayCables();   // ????????
    void removeCable();     // ????????
};
