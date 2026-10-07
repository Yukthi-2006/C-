#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle() : length(0), width(0) {}

    void setLength(double l) {
        if (l >= 0) {
            length = l;
        } else {
            std::cout << "Invalid length! Negative values rejected.\n";
        }
    }

    void setWidth(double w) {
        if (w >= 0) {
            width = w;
        } else {
            std::cout << "Invalid width! Negative values rejected.\n";
        }
    }

    double area() const {
        return length * width;
    }

    double perimeter() const {
        return 2 * (length + width);
    }
};

int main() {
    Rectangle rect;

    // Testing setters with positive and negative values
    rect.setLength(5.0);
    rect.setWidth(-3.0); // Rejected
    rect.setWidth(4.0);  // Accepted

    std::cout << "Area: " << rect.area() << "\n";
    std::cout << "Perimeter: " << rect.perimeter() << "\n";

    return 0;
}