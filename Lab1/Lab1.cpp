#include <iostream>
#include <vector>
using namespace std;

class CoaxialCable {
private:
    double Z; // хвильовий опір
    double D; // діаметр
    double L; // довжина

public:
    // Конструктор за замовчуванням
    CoaxialCable() {
        Z = 50;
        D = 5;
        L = 1;
        cout << "Створено кабель за замовчуванням.\n";
    }

    // Конструктор з параметрами
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
            cout << "Некоректні дані. Встановлено значення за замовчуванням.\n";
        }
    }

    // Метод для виводу
    void print() {
        cout << "Кабель: Z=" << Z << " Ом, D=" << D << " мм, L=" << L << " м\n";
    }

    // Сеттер довжини з перевіркою
    void setLength(double l) {
        if (l > 0) L = l;
        else cout << "Помилка: довжина повинна бути додатною.\n";
    }

    double getZ() { return Z; }

    // Статичний метод фільтрації
    static vector<CoaxialCable> filterByZ(vector<CoaxialCable> cables, double targetZ) {
        vector<CoaxialCable> res;
        for (auto& c : cables) {
            if (c.Z == targetZ) res.push_back(c);
        }
        return res;
    }
};

int main() {
    // Створення кабеля
    CoaxialCable a(50, 5, 10);
    CoaxialCable b(75, 7, 5);
    CoaxialCable c(50, 6, 25);

    vector<CoaxialCable> list = { a, b, c };

    cout << "--- Всі кабелі ---\n";
    for (auto& x : list) x.print();

    cout << "--- Тест помилкового значення ---\n";
    a.setLength(-3);

    cout << "--- Фільтрація (Z=50) ---\n";
    vector<CoaxialCable> filt = CoaxialCable::filterByZ(list, 50);
    for (auto& x : filt) x.print();

    return 0;
}

