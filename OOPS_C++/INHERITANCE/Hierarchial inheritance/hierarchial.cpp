#include <iostream>
using namespace std;

// Base class: Person
class Person {
protected:
    string fullName;
    int age;
public:
    // Normal constructor (without inline initialization)
    Person(string name, int age) {
        fullName = name;
        this->age = age;
    }

    // Function to display personal details
    void displayPersonalInfo() const {
        cout << "Name: " << fullName << "\nAge: " << age << endl;
    }
};

// Derived class: Student (inherits from Person)
class Student : public Person {
private:
    int universityRollNumber;
public:
    // Normal constructor
    Student(string name, int age, int rollNumber) : Person(name, age) {
        universityRollNumber = rollNumber;
    }

    // Function to display student details
    void displayStudentInfo() const {
        displayPersonalInfo();  // Calling base class function
        cout << "University Roll Number: " << universityRollNumber << endl;
    }
};

// Derived class: Employee (inherits from Person)
class Employee : public Person {
private:
    string companyName;
public:
    // Normal constructor
    Employee(string name, int age, string company) : Person(name, age) {
        companyName = company;
    }

    // Function to display employee details
    void displayEmployeeInfo() const {
        displayPersonalInfo();  // Calling base class function
        cout << "Company: " << companyName << endl;
    }
};

// Main function
int main() {
    // Creating objects for Student and Employee
    Student student1("Rishav", 21, 2119475);
    Employee employee1("Ramsy", 35, "RVD Tech Inc.");

    cout << "\nStudent Details:\n";
    student1.displayStudentInfo();

    cout << "\nEmployee Details:\n";
    employee1.displayEmployeeInfo();

    return 0;
}
