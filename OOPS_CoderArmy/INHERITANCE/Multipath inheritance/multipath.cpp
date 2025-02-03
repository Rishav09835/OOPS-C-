//multipath inheritance leads to having multiple copies of base class members in child classes that access them.
//here both youtuber and coder class have copies of name in them and when student class is derived from them
//it has multiple copies of name variable which is in human class. 
//to resolve this and ensure that only 1 copy of base class member is shared b/w derived class we use "virtual" keyword.
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

class Human{
    public:
    string name;
    void show(){
        cout<<"Hi my name is : "<<name<<endl;
    }
};

class Youtuber: public virtual Human{
    public:
    string channel;
    void utube_detail(){
        cout<<"my youtube channel is : "<<channel<<endl;
    }
};

class Coder: public virtual Human{
    public:
    string platform;
    void codingat(){
        cout<<"i code at "<<platform<<endl;
    }
};

class Student: public Youtuber, public Coder{
    public:
    int std_id;
    Student(string name, string channel, string platform, int std_id){
        this->name = name;
        this->channel = channel;
        this->platform = platform;
        this->std_id = std_id;
    }
};


int main(){
    Student S1("Rishav","RVDcoder","Leetcode",2119475);
    S1.show();
    S1.utube_detail();
    S1.codingat();
    return 0;
}