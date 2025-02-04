/*PROGRAM TO SHOW WHICH CONSTRUCTOR IS CALLED FIRST CHILD OR PARENT
parent class constructor is always called first to create parent class so
that child can use it.
*/
#include<bits/stdc++.h>
using namespace std;

class Person{
public:
    Person(){
        cout<<"Person constructor.."<<endl;
    }
};

class Student : public Person{
public:
    Student(){
        cout<<"Student constructor.."<<endl;
    }

};


int main(){
    Student R1;
    return 0;
}