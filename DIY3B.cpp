#include <iostream>

class Counter {
private:
    int count;

public:
    Counter() : count(0) {}

    void increment() {
        count++;
    }

    void reset() {
        count = 0;
    }

    int get() const {
        return count;
    }
};

int main() {
    // Array of 3 counter objects
    Counter counters[3];

    // Exercising counters
    counters[0].increment();
    counters[0].increment();

    counters[1].increment();
    counters[1].increment();
    counters[1].increment();

    counters[2].increment();
    counters[2].reset();

    // Displaying counter values
    for (int i = 0; i < 3; ++i) {
        std::cout << "Counter " << i + 1 << " value: " << counters[i].get() << "\n";
    }

    return 0;
}