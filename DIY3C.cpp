#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    void setData(double r, double i) {
        real = r;
        imag = i;
    }

    void display() const {
        std::cout << real << " + " << imag << "i\n";
    }
};

int main() {
    // Small array of complex numbers
    Complex arr[3];

    arr[0].setData(2.5, 4.0);
    arr[1].setData(1.2, 3.8);
    arr[2].setData(5.0, 7.1);

    std::cout << "Array of Complex Numbers:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "Number " << i + 1 << ": ";
        arr[i].display();
    }

    return 0;
}