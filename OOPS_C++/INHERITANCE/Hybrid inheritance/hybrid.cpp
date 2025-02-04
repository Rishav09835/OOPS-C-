#include<bits/stdc++.h>
using namespace std;
//base class
class Teacher{
    public:
    void show(){
        cout<<"I am a teacher\n";
    }
};

//base class
class Male{
    public:
    void printMale(){
        cout<<"I am a male\n";
    }
};

//base class
class Female{
    public:
    void printFemale(){
        cout<<"I am a female\n";
    }
};

class Boy: public Teacher, public Male{
    public:
    void printBoy(){
        cout<<"I am a Boy\n";
    }
};

class Girl: public Teacher, public Female{
    public:
    void printGirl(){
        cout<<"i am a girl\n";
    }
};

int main(){
    Girl g1;
    Boy b1;
    g1.show();
    g1.printFemale();
    b1.printBoy();
    b1.printBoy();
    return 0;
}