#include<bits/stdc++.h>
using namespace std;

class Customer{
private:
    string name;
    int accno, balance;
    static int total_customer;
    static int total_cash_inbank;
public:
    Customer(string name, int accno, int balance){
        this->name = name;
        this->accno = accno;
        this->balance = balance;
        total_customer++;
        total_cash_inbank+=balance;
    }
    void cust_details(){
        cout<<name<<" "<<accno<<" "<<balance<<endl;
    }
    //static member function : it can only access static variables(data members).
    static void Total_cust(){
        cout<<total_customer<<endl;
    }
    //another static member function.
    static void sbi_totalcash(){
        cout<<total_cash_inbank<<endl;
    }
};
int Customer :: total_customer = 0;
int Customer :: total_cash_inbank = 0;
//static data members can be accessed by non static functions, but static functions can only access static data members
//they cannot access non static variables as they are part of objects and not class.
int main(){
    Customer C1("Rishav",2119468,2000);
    Customer C2("Raj",23980,800);
    Customer C3("Monk",234566,1200);
    Customer :: Total_cust();
    Customer :: sbi_totalcash();
    return 0;
}