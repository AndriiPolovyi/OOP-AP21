#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

class CoaxialCable {
private:
    double Z; 
    double D; 
    double L; 

public:
    
    CoaxialCable() {
        Z = 50;
        D = 5;
        L = 1;
        cout << "Stvoreno kabel za zamovchuvannyam.\n";
    }

    CoaxialCable(double z, double d, double l) {
        if (z > 0 && d > 0 && l > 0) {
            Z = z;
            D = d;
            L = l;
        }
        else {
            Z = 50;
            D = 5;
            L = 1;
            cout << "Nekorektni dani. Vstanovleno znachennya za zamovchuvannyam.\n";
        }
    }

    ~CoaxialCable() {
        cout << "Destruktor: kabel Z=" << Z << " znyshcheno.\n";
    }

    void input() {
        cout << "Vvedit Z, D, L: ";
        double z, d, l;
        cin >> z >> d >> l;
        if (z > 0 && d > 0 && l > 0) {
            Z = z;
            D = d;
            L = l;
        }
        else {
            cout << "Pomylka vvedennya! Vstanovleno znachennya za zamovchuvannyam.\n";
            Z = 50;
            D = 5;
            L = 1;
        }
    }

    void print() const {
        cout << "Kabel: Z=" << Z << " Om, D=" << D << " mm, L=" << L << " m\n";
    }

    void setLength(double l) {
        if (l > 0) L = l;
        else cout << "Pomylka: dovzhyna povynna buty dodatnoju.\n";
    }

    double getZ() const { return Z; }

    static vector<CoaxialCable> filterByZ(const vector<CoaxialCable>& cables, double targetZ) {
        vector<CoaxialCable> res;
        for (auto& c : cables) {
            if (c.Z == targetZ) res.push_back(c);
        }
        if (res.empty()) {
            cout << "Kabeliv z Z=" << targetZ << " ne znajdeno.\n";
        }
        return res;
    }
};

int main() {
    SetConsoleOutputCP(65001);

    CoaxialCable a(50, 5, 10);
    CoaxialCable b(75, 7, 5);
    CoaxialCable c(50, 6, 25);

    vector<CoaxialCable> list = { a, b, c };

    cout << "--- Vsi kabeli ---\n";
    for (auto& x : list) x.print();

    cout << "--- Test pomylkovoho znachennya ---\n";
    a.setLength(-3);

    cout << "--- Vvedennya novogo kabelya ---\n";
    CoaxialCable d;
    d.input();
    list.push_back(d);

    cout << "--- Filtraciya (Z=50) ---\n";
    vector<CoaxialCable> filt = CoaxialCable::filterByZ(list, 50);
    for (auto& x : filt) x.print();

    cout << "--- Filtraciya (Z=100) ---\n";
    vector<CoaxialCable> filt2 = CoaxialCable::filterByZ(list, 100);
    for (auto& x : filt2) x.print();

    return 0;
}
