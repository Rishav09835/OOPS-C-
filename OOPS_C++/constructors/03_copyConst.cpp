//copy constructor -> cpp provides a default copy constructor(only does shallow copies..) , we can create our own too
/*              shallow vs deep copy
shallow copy = of an object copies all the values from one object to another.
                issues arise when used with dynamic memory allocation.
Deep copy = of an object copies all the values from one object to another + also makes separate copies of any 
            dynamically allocated memory.
            we have to write deep copy constructor ourselves as c++ only provide shallow copy constructor.
*/

//code for shallow copy constructor.
#include<iostream>
using namespace std;

class Student{
public:
    string name;
    int age;
    double *cgpaptr;
    public:
    // Parameterized constructor (allocating dynamic memory)
    Student(string name, int age, double cgpa) {
        this->name = name;
        this->age = age;
        cgpaptr = new double;  // Allocating memory dynamically
        *cgpaptr = cgpa;
    }

    // Shallow Copy Constructor (like the default copy constructor)
    Student(const Student &obj) { 
        cout << "Shallow Copy Constructor Called!\n";
        this->name = obj.name;
        this->age = obj.age;
        this->cgpaptr = obj.cgpaptr;  // Shallow copy: pointer copied, not new memory
    }

    void getDetails() {
        cout << "Name: " << name << ", Age: " << age << ", CGPA: " << *cgpaptr << endl;
    }
};

int main() {
    Student s1("Rishav", 21, 8.07);
    cout << "Before modification:\n";
    s1.getDetails();

    Student s2(s1);  // Shallow copy
    s2.name = "Mayank";
    s2.getDetails();
    *(s2.cgpaptr) = 9.07;  // Modifying copied object's CGPA

    cout << "\nAfter modification:\n";
    s2.getDetails();
    
    cout << "\nChecking original (s1):\n";
    s1.getDetails();  // s1's CGPA is also changed -> PROBLEM with shallow copy when we have dynamic memory allocation.

    cout << "\nThat's why we need a Deep Copy Constructor!\n";
    return 0;
}
