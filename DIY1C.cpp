#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Reverser {
    std::string text;
public:
    Reverser(std::string s) : text(s) {}

    void display() {
        std::stringstream ss(text);
        std::string word;
        std::vector<std::string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        std::cout << "Reversed sentence: ";
        for (int i = words.size() - 1; i >= 0; --i) {
            std::cout << words[i] << (i > 0 ? " " : "");
        }
        std::cout << "\n";
    }
};

int main() {
    std::string s;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, s);

    Reverser r(s);
    r.display();

    return 0;
}