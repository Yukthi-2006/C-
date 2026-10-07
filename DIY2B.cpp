#include <iostream>
#include <cmath>

class MathUtils {
public:
    int power(int base, int exp = 2) {
        return std::pow(base, exp);
    }
};

int main() {
    MathUtils mu;

    std::cout << "power(5): " << mu.power(5) << "\n";       // Output: 25
    std::cout << "power(2, 10): " << mu.power(2, 10) << "\n"; // Output: 1024

    return 0;
}