#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray {
    int *arr;
    int size;

public:
    SafeArray(int s) : size(s) {
        arr = new int[size]{0};
    }

    // Rule of Three: Copy Constructor
    SafeArray(const SafeArray &other) : size(other.size) {
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // Rule of Three: Copy Assignment Operator
    SafeArray& operator=(const SafeArray &other) {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            arr = new int[size];
            for (int i = 0; i < size; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    // Destructor
    ~SafeArray() {
        delete[] arr;
    }

    // Bounds-checked subscript operator
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("SafeArray error: Index out of range!");
        }
        return arr[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("SafeArray error: Index out of range!");
        }
        return arr[index];
    }

    int getSize() const { return size; }
};

int main() {
    try {
        SafeArray sa(5);
        sa[0] = 10;
        sa[2] = 30;
        cout << "sa[2] = " << sa[2] << endl;

        // This will trigger an out_of_range exception
        cout << "Attempting to access sa[10]..." << endl;
        sa[10] = 99;
    } catch (const exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    return 0;
}