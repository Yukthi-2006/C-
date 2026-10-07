#include <iostream>

class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    void display() const {
        std::cout << (hours < 10 ? "0" : "") << hours << ":"
                  << (minutes < 10 ? "0" : "") << minutes;
    }

    // Friend function declaration
    friend Time laterOf(Time t1, Time t2);
};

// Friend function definition
Time laterOf(Time t1, Time t2) {
    int totalMin1 = t1.hours * 60 + t1.minutes;
    int totalMin2 = t2.hours * 60 + t2.minutes;

    return (totalMin1 >= totalMin2) ? t1 : t2;
}

int main() {
    Time t1(10, 45);
    Time t2(14, 15);

    std::cout << "Time 1: "; t1.display(); std::cout << "\n";
    std::cout << "Time 2: "; t2.display(); std::cout << "\n";

    Time later = laterOf(t1, t2);
    std::cout << "Later time is: ";
    later.display();
    std::cout << "\n";

    return 0;
}