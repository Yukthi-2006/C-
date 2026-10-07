#include <iostream>

class Counter {
private:
    static int totalCreated;
    static int currentlyAlive;

public:
    Counter() {
        totalCreated++;
        currentlyAlive++;
    }

    ~Counter() {
        currentlyAlive--;
    }

    static void displayStats() {
        std::cout << "Total created: " << totalCreated 
                  << " | Currently alive: " << currentlyAlive << "\n";
    }
};

// Definition of static variables outside class
int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main() {
    Counter::displayStats();

    Counter c1, c2;
    Counter::displayStats();

    {
        Counter c3;
        Counter::displayStats();
    } // c3 is destroyed here

    Counter::displayStats();

    return 0;
}