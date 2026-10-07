#include <iostream>

class Tracer {
private:
    int id;

public:
    Tracer(int i) : id(i) {
        std::cout << "Tracer " << id << " created\n";
    }

    ~Tracer() {
        std::cout << "Tracer " << id << " destroyed\n";
    }
};

int main() {
    std::cout << "--- Loop Execution ---\n";
    for (int i = 1; i <= 3; ++i) {
        Tracer* t = new Tracer(i);

        // Deleting frees the object and invokes the destructor
        delete t; 

        // NOTE: Commenting out 'delete t;' causes a memory leak,
        // which can be detected when compiled with:
        // g++ -fsanitize=address main.cpp
    }

    return 0;
}