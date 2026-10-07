#include <iostream>

class Order {
private:
    static int nextID;
    int orderID;

public:
    Order() {
        orderID = nextID++;
    }

    void display() const {
        std::cout << "Order ID: " << orderID << "\n";
    }
};

// Initialize starting ID to 1001
int Order::nextID = 1001;

int main() {
    Order o1;
    Order o2;
    Order o3;

    o1.display();
    o2.display();
    o3.display();

    return 0;
}