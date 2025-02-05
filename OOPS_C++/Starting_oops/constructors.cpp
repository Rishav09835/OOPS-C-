#include<bits/stdc++.h>
using namespace std;

class Teacher{
private:
    double salary;
public:
    string name;
    string dept;
    string subject;
    //non-parameterized constructor. 
    // Teacher(){
    //     cout<<"hi i am called";
    // }

    //parameterized constructor
    // Teacher(string n, string dep, string sub, double sal){
    //     name = n;
    //     dept = dep;
    //     subject = sub;
    //     salary = sal;
    // }

    //understanding why this pointer is needed.(To resolve ambiguity in program)
    Teacher(string name, string dept, string subject, double salary){
    /*ye property ka name hai*/      //name = name; /*ye humara parameter*/
     /*ye dept property ka name */   //dept = dept; /*ye parameter*/
    //this is confusing for compiler use samjh ni ayega ki object ki property konsi hai. toh object ki prop ko 
    // dikane ke liye we use this pointer
         this->name = name;
         //also can be written as *(this).name = name; 
         this->dept = dept;
         this->subject = subject;
         this->salary = salary;
    }

    //setter
    void setsal(double s){
        salary = s;
    }
    //getter
    double getsal(){
        return salary;
    }

    void getInfo(){
        cout<<name<<"name set by parameterized const\n";
        cout<<dept<<"set using parameterized const\n";
        cout<<salary<<"set using parameterized const\n";
    }
};

int main(){
//object of class Teacher.
Teacher t1("Rishav","CSE","Maths",120000); //constructor called automatically.
// Teacher t2; constructor called automatically. every time an object is created construtor is called autom. 
t1.getInfo();
return 0;    
}