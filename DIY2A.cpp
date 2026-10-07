#include <iostream>
#include <cmath>

class VolumeCalculator {
public:
    // Cube: 1 argument
    double volume(double side) {
        return side * side * side;
    }

    // Cuboid: 3 arguments
    double volume(double l, double w, double h) {
        return l * w * h;
    }

    // Cylinder: 2 arguments (radius, height)
    double volume(double r, double h) {
        return M_PI * r * r * h;
    }
};

int main() {
    VolumeCalculator vc;
    
    std::cout << "Volume of Cube (side 4): " << vc.volume(4.0) << "\n";
    std::cout << "Volume of Cuboid (3, 4, 5): " << vc.volume(3.0, 4.0, 5.0) << "\n";
    std::cout << "Volume of Cylinder (r=3, h=7): " << vc.volume(3.0, 7.0) << "\n";

    return 0;
}