#include <iostream>
#include <algorithm>

class MathMin {
public:
    // Two integers overload
    inline int minVal(int a, int b) {
        return (a < b) ? a : b;
    }

    // Three integers overload
    inline int minVal(int a, int b, int c) {
        return minVal(minVal(a, b), c);
    }
};

int main() {
    MathMin m;

    std::cout << "Min of 15 and 8: " << m.minVal(15, 8) << "\n";
    std::cout << "Min of 12, 5, and 20: " << m.minVal(12, 5, 20) << "\n";

    return 0;
}