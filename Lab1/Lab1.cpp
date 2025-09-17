#include <iostream>
#include <vector>
using namespace std;

class CoaxialCable {
private:
    double Z; // ��������� ���
    double D; // ������
    double L; // �������

public:
    // ����������� �� �������������
    CoaxialCable() {
        Z = 50;
        D = 5;
        L = 1;
        cout << "�������� ������ �� �������������.\n";
    }

    // ����������� � �����������
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
            cout << "��������� ���. ����������� �������� �� �������������.\n";
        }
    }

    // ����� ��� ������
    void print() {
        cout << "������: Z=" << Z << " ��, D=" << D << " ��, L=" << L << " �\n";
    }

    // ������ ������� � ���������
    void setLength(double l) {
        if (l > 0) L = l;
        else cout << "�������: ������� ������� ���� ��������.\n";
    }

    double getZ() { return Z; }

    // ��������� ����� ����������
    static vector<CoaxialCable> filterByZ(vector<CoaxialCable> cables, double targetZ) {
        vector<CoaxialCable> res;
        for (auto& c : cables) {
            if (c.Z == targetZ) res.push_back(c);
        }
        return res;
    }
};

int main() {
    // ��������� ������
    CoaxialCable a(50, 5, 10);
    CoaxialCable b(75, 7, 5);
    CoaxialCable c(50, 6, 25);

    vector<CoaxialCable> list = { a, b, c };

    cout << "--- �� ����� ---\n";
    for (auto& x : list) x.print();

    cout << "--- ���� ����������� �������� ---\n";
    a.setLength(-3);

    cout << "--- Գ�������� (Z=50) ---\n";
    vector<CoaxialCable> filt = CoaxialCable::filterByZ(list, 50);
    for (auto& x : filt) x.print();

    return 0;
}

