#include <iostream>

class Stack {
private:
    int* arr;
    int capacity;
    int top;

public:
    Stack(int cap) : capacity(cap), top(-1) {
        arr = new int[capacity];
    }

    // Destructor releases dynamic memory
    ~Stack() {
        delete[] arr;
    }

    void push(int val) {
        if (top == capacity - 1) {
            std::cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = val;
    }

    void pop() {
        if (top == -1) {
            std::cout << "Stack Underflow!\n";
            return;
        }
        std::cout << "Popped: " << arr[top--] << "\n";
    }
};

int main() {
    Stack s(3);
    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();
    s.pop();

    return 0;
}