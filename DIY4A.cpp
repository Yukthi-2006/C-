#include <iostream>

class Matrix {
private:
    int rows, cols;
    int** data;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols]{0}; // initialized to 0
        }
    }

    // Deep Copy Constructor
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Destructor to free memory
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void set(int r, int c, int val) { data[r][c] = val; }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    Matrix m1(2, 3);
    m1.set(0, 0, 5);
    m1.set(1, 2, 9);

    std::cout << "Original Matrix:\n";
    m1.display();

    Matrix m2 = m1; // Triggers Deep Copy
    std::cout << "Copied Matrix:\n";
    m2.display();

    return 0;
}