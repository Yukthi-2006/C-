#include <iostream>
#include <numeric> // for std::gcd
using namespace std;

class Fraction {
    int num, den;

    void simplify() {
        if (den == 0) {
            den = 1;
        }
        if (den < 0) { // Keep denominator positive
            num = -num;
            den = -den;
        }
        int g = std::gcd(abs(num), den);
        num /= g;
        den /= g;
    }

public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) {
        simplify();
    }

    friend ostream& operator<<(ostream &os, const Fraction &f) {
        os << f.num << "/" << f.den;
        return os;
    }

    friend istream& operator>>(istream &is, Fraction &f) {
        char slash;
        is >> f.num >> slash >> f.den;
        f.simplify();
        return is;
    }
};

int main() {
    Fraction f1(10, -15);
    cout << "Simplified Fraction (10/-15): " << f1 << endl;

    Fraction f2;
    cout << "Enter a fraction in the format numerator/denominator (e.g., 3/4): ";
    if (cin >> f2) {
        cout << "You entered: " << f2 << endl;
    }
    return 0;
}