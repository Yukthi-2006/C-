#include <iostream>
#include <cmath>
using namespace std;

class Money {
    long rupees;
    int paise;

    void normalize() {
        if (paise >= 100) {
            rupees += paise / 100;
            paise %= 100;
        } else if (paise < 0) {
            long r = (abs(paise) + 99) / 100;
            rupees -= r;
            paise += r * 100;
        }
    }

public:
    Money(long r = 0, int p = 0) : rupees(r), paise(p) {
        normalize();
    }

    Money operator+(const Money &m) const {
        return Money(rupees + m.rupees, paise + m.paise);
    }

    Money operator-(const Money &m) const {
        return Money(rupees - m.rupees, paise - m.paise);
    }

    friend ostream& operator<<(ostream &os, const Money &m) {
        os << m.rupees << " Rs. " << m.paise << " p.";
        return os;
    }
};

int main() {
    Money m1(5, 75), m2(2, 50);
    cout << "m1 = " << m1 << endl;
    cout << "m2 = " << m2 << endl;
    cout << "m1 + m2 = " << (m1 + m2) << endl;
    cout << "m1 - m2 = " << (m1 - m2) << endl;
    return 0;
}