#include <iostream>
#include <string>
#include <algorithm>

class Anagram {
    std::string w1, w2;
public:
    Anagram(std::string a, std::string b) : w1(a), w2(b) {}

    bool check() {
        if (w1.length() != w2.length()) return false;
        std::sort(w1.begin(), w1.end());
        std::sort(w2.begin(), w2.end());
        return w1 == w2;
    }
};

int main() {
    std::string word1, word2;
    std::cout << "Enter first word: ";
    std::cin >> word1;
    std::cout << "Enter second word: ";
    std::cin >> word2;

    Anagram a(word1, word2);
    if (a.check()) {
        std::cout << "Anagram\n";
    } else {
        std::cout << "Not Anagram\n";
    }

    return 0;
}