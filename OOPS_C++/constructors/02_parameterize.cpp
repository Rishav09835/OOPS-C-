//parameterized constructor.
#include<iostream>
using namespace std;

class Student{
private:
    string name;
    int age;
    int cgpa;
public:
    //we can overload constructor using different no. of parameters and different return type for parameters.
    //this keyword is used to resolve ambiguity in our code.
    Student(string name, int age, int cgpa){
        this->name = name; //(*this).name = name is also correct.
        this->age = age;
        this->cgpa = cgpa;
        cout<<"copy constructor called successfully"<<endl;
    }
    void getDetails(){
        cout<<"name: "<<name<<endl<<"age: "<<age<<endl<<"cgpa: "<<cgpa<<endl;
    }
};

int main(){
    Student s1("Rishav",21,8);
    s1.getDetails();
    return 0;
}