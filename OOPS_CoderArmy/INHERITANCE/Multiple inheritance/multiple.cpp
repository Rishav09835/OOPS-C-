#include <iostream>
using namespace std;

// Base class: Person
class Person {
protected:
    string fullName;
    int age;
public:
    // Normal constructor
    Person(string name, int age) {
        fullName = name;
        this->age = age;
    }

    // Function to display personal details
    void displayPersonalInfo() const {
        cout << "Name: " << fullName << "\nAge: " << age << endl;
    }
};

// Base class: Worker
class Worker {
protected:
    string companyName;
public:
    // Normal constructor
    Worker(string company) {
        companyName = company;
    }

    // Function to display work details
    void displayWorkInfo() const {
        cout << "Company: " << companyName << endl;
    }
};

// Derived class: Engineer (inherits from both Person and Worker)
class Engineer : public Person, public Worker {
private:
    string specialization;
public:
    // Normal constructor
    Engineer(string name, int age, string company, string field) 
        : Person(name, age), Worker(company) {
        specialization = field;
    }

    // Function to display engineer details
    void displayEngineerInfo() const {
        displayPersonalInfo();  // Calling Person's function
        displayWorkInfo();      // Calling Worker's function
        cout << "Specialization: " << specialization << endl;
    }
};

// Main function
int main() {
    // Creating object for Engineer
    Engineer eng1("Alice Johnson", 30, "TechCorp", "Software Engineering");

    cout << "\nEngineer Details:\n";
    eng1.displayEngineerInfo();

    return 0;
}
