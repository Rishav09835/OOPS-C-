#include<bits/stdc++.h>
using namespace std;

class Customer{
private:
    string name;
    int accno, balance;
    // int total_customer = 0; we want this value to be same for all objects, so this wont work.
    static int total_customer;//static member must be declared inside class.
public:
    Customer(string name, int accno, int balance){
        this->name = name;
        this->accno = accno;
        this->balance = balance;
        total_customer++;
    }
    void cust_details(){
        cout<<name<<" "<<accno<<" "<<balance<<" "<<total_customer<<endl;
    }
};
int Customer :: total_customer = 0; //must be initialized outside class;

int main(){

    Customer C1("Rishav",2119468,20000000);
    C1.cust_details();
    Customer C2("Monk",234566,12000);
    C2.cust_details();
    // **static data member can be accesed directly without an object.
    // Customer :: total_customer = 10; given that static data member is written in public place.
    
    // to access private static data member directly using Class
    // we create static data members -> see next cpp file.
    return 0;
}