#include <iostream>
#include <string>

// Base Level
class Shape {
protected:
    std::string color;

public:
    Shape(const std::string& c) : color(c) {
        std::cout << "[1] Shape Constructor called (Color: " << color << ")\n";
    }

    ~Shape() {
        std::cout << "[1] Shape Destructor called\n";
    }
};

// Intermediate Level
class Polygon : public Shape {
protected:
    int numSides;

public:
    Polygon(const std::string& c, int sides) : Shape(c), numSides(sides) {
        std::cout << "[2] Polygon Constructor called (Sides: " << numSides << ")\n";
    }

    ~Polygon() {
        std::cout << "[2] Polygon Destructor called\n";
    }
};

// Derived Level
class Rectangle : public Polygon {
private:
    double area;

public:
    Rectangle(const std::string& c, int sides, double a) 
        : Polygon(c, sides), area(a) {
        std::cout << "[3] Rectangle Constructor called (Area: " << area << ")\n";
    }

    ~Rectangle() {
        std::cout << "[3] Rectangle Destructor called\n";
    }

    void display() const {
        std::cout << "\nRectangle Details -> Color: " << color 
                  << ", Sides: " << numSides 
                  << ", Area: " << area << "\n\n";
    }
};

int main() {
    std::cout << "--- Creating Rectangle Object ---\n";
    Rectangle rect("Red", 4, 45.5);

    rect.display();

    std::cout << "--- Destroying Rectangle Object ---\n";
    return 0;
}