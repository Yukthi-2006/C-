#include <iostream>
#include <string>

// Base Class
class Employee {
protected:
    std::string name;
    int id;

public:
    Employee(const std::string& empName, int empId) 
        : name(empName), id(empId) {}

    void displayDetails() const {
        std::cout << "ID: " << id << "\nName: " << name << std::endl;
    }
};

// Derived Class 1
class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(const std::string& empName, int empId, int size)
        : Employee(empName, empId), teamSize(size) {}

    void displayDetails() const {
        Employee::displayDetails();
        std::cout << "Role: Manager\nTeam Size: " << teamSize << "\n" << std::endl;
    }
};

// Derived Class 2
class Engineer : public Employee {
private:
    std::string skill;

public:
    Engineer(const std::string& empName, int empId, const std::string& empSkill)
        : Employee(empName, empId), skill(empSkill) {}

    void displayDetails() const {
        Employee::displayDetails();
        std::cout << "Role: Engineer\nSkill: " << skill << "\n" << std::endl;
    }
};

int main() {
    Manager mgr("Alice Smith", 101, 8);
    Engineer eng("Bob Jones", 102, "Embedded Systems");

    std::cout << "--- Employee Details ---\n";
    mgr.displayDetails();
    eng.displayDetails();

    return 0;
}