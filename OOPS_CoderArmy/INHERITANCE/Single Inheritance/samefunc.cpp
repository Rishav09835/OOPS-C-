/*if same name functions exist in child and parent class then the class whose
object is created, compiler waha jake dekhega ki wo function hai ki nahi, if its there
the code will be execute and if not compiler will go to its parent class to find that function.*/

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
    void display(){
        cout<<name<<" "<<age<<endl;
    }
};

class Student : public Human{
    int roll;
    int fees;
public:
    //calling parent constructor in child class;
    Student(int roll, int fees, int age, string name): Human(age, name){
        this->roll = roll;
        this->fees = fees; 
    }
    /*    void display(){
        cout<<name<<" "<<age<<" "<<fees<<" "<<roll;
    } */
};


int main(){
    Student R1(12,80000,21,"Rishav");
    R1.display();
    return 0;
}