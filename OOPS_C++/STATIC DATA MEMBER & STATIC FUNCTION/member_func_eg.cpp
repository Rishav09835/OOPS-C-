#include<iostream>
#include<string>
using namespace std;

class Name{
    public:
    static string create_name(string first, string last){
        return first + last;
    }
};

int main(){
    //no object needed.
    cout<<"Name created is: "<<Name::create_name("Rishav"," Dobriyal");
}