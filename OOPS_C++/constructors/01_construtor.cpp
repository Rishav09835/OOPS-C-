#include<iostream>
using namespace std;

class Student{
private:
    string name;
    int age;
    int cgpa;
public:
    //default constructor -> compiler creates it even if we don't
    Student(){

    }
    void setDetails(string name, int age, int cgpa)
    {
        this->name = name;
        this->age = age;
        this->cgpa = cgpa;
    }
    void getDetails(){
        cout<<"name: "<<name<<endl<<"age: "<<age<<endl<<"cgpa: "<<cgpa<<endl;
    }
};

int main(){
    Student s1;
    s1.setDetails("Rishav Dobriyal", 21, 8);
    s1.getDetails();
    return 0;
}