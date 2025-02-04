/* A BASIC INHERITANCE PROGRAM*/
#include<bits/stdc++.h>
using namespace std;

class Person{
protected:
    string name;
    string gender;
};

class Student : public Person{
private:
    string Major;
public:
    Student(string name, string gender, string Major){
        this->name = name;
        this->gender = gender;
        this -> Major = Major;
    }
    void display(){
    cout<<Major<<" "<<name<<" "<<gender;
    }

};

int main(){
    Student R1("Rishav", "Male","CSE");
    R1.display();
    return 0;
}