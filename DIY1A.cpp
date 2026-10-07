#include <iostream>
#include <string>
#include <cctype>

class Counter {
    std::string text;
public:
    Counter(std::string s) : text(s) {}

    void process() {
        int v = 0, c = 0;
        for (char ch : text) {
            if (std::isalpha(ch)) {
                char low = std::tolower(ch);
                if (low == 'a' || low == 'e' || low == 'i' || low == 'o' || low == 'u') v++;
                else c++;
            }
        }
        std::cout << "Vowels: " << v << "\nConsonants: " << c << "\n";
    }
};

int main() {
    std::string s;
    std::cout << "Enter a sentence: "; // <-- ADD THIS LINE
    std::getline(std::cin, s);
    Counter(s).process();
    return 0;
}