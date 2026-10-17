#include <iostream>
#include <string>

// Base Class
class Person {
protected:
    std::string name;

public:
    Person(const std::string& personName) : name(personName) {
        std::cout << "Person constructor called for: " << name << "\n";
    }
};

// Virtual Derived Class 1
class Student : virtual public Person {
protected:
    int studentID;

public:
    Student(const std::string& personName, int sID)
        : Person(personName), studentID(sID) {}
};

// Virtual Derived Class 2
class Employee : virtual public Person {
protected:
    int employeeID;

public:
    Employee(const std::string& personName, int eID)
        : Person(personName), employeeID(eID) {}
};

// Most Derived Class (Diamond Resolution)
class TA : public Student, public Employee {
private:
    std::string assignedCourse;

public:
    // With virtual base classes, the most derived class directly initializes the virtual base (Person)
    TA(const std::string& name, int sID, int eID, const std::string& course)
        : Person(name), Student(name, sID), Employee(name, eID), assignedCourse(course) {}

    void displayDetails() const {
        std::cout << "\n--- Teaching Assistant Info ---\n";
        std::cout << "Name: " << name << "\n"           // Unambiguous direct access to Person member
                  << "Student ID: " << studentID << "\n"
                  << "Employee ID: " << employeeID << "\n"
                  << "Course: " << assignedCourse << "\n";
    }
};

int main() {
    TA taObj("Alex Morgan", 8001, 1052, "Data Structures");
    taObj.displayDetails();

    return 0;
}