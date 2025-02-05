#include<bits/stdc++.h>
using namespace std;
//copy constructor..
class Teacher{
private:
    double salary;
public:
    string name;
    string dept;
    string subject;
    //parameterized
    Teacher(string name, string dept, string subject, double salary){
         this->name = name;
         this->dept = dept;
         this->subject = subject;
         this->salary = salary;
    }

    //creating our own copy constructor just like default onee.
    Teacher(Teacher &obj){
        cout<<"I am your custom copy constructor."<<endl ;
        this->name = obj.name;
        this->dept = obj.dept;
        this->subject = obj.subject;
        this->salary = obj.salary;
    }

    void setsal(double s){
        salary = s;
    }
    
    double getsal(){
        return salary;
    }

    void getInfo(){
        cout<<name<<endl;
        cout<<dept<<endl;
        cout<<salary;
    }
};

int main(){
Teacher t1("Rishav","CSE","Maths",120000); //constructor called automatically.
// t1.getInfo();
Teacher t2(t1); 
t2.getInfo();
return 0;    
}