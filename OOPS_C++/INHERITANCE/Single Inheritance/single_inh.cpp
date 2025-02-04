//single inheritance
//we can call parent class constructor in child class
#include<bits/stdc++.h>
using namespace std;

class Human{
protected:
    int age;
    string name;
public:
    Human(int age, string name){
        this->age = age;
        this->name = name;
    }
};

class Student : public Human{
    int roll;
    int fees;
public:
   /* Student(int roll, int fees, int age, string name){
        this->roll = roll;
        this->fees = fees;
        this->age = age;
        this ->name = name;
    } */
    
    //calling parent constructor in child class;
    Student(int roll, int fees, int age, string name): Human(age, name){
        this->roll = roll;
        this->fees = fees; 
       /* this->age = age;
        this ->name = name; */
    }
    void display(){
        cout<<name<<" "<<age<<" "<<fees<<" "<<roll;
    }
};


int main(){
    Student R1(12,80000,21,"Rishav");
    R1.display();
    return 0;
}