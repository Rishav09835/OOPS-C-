/*WHEN derived class inherits from another derived class forming
a chain of inheritance => multi level inheritance.*/
#include<bits/stdc++.h>
using namespace std;

class Anime{
protected:
    string type;
public:

    void animetype(){
        cout<<"This is the anime type: "<<type<<endl;
    }
};

class Shounen : public Anime{
protected:
    string genre;
public:
    void show_genre(){
        cout<<"Genre is : "<<genre<<endl;
    }
};

class MHA : public Shounen{
    protected:
    string name;
    public:
    MHA(string type, string genre, string name){
        this->type = type;
        this->genre = genre;
        this->name = name;
    }
    void display_name(){
        cout<<"Name of anime is : "<<name<<endl;
    }
};

int main(){
    MHA A1("Action","Shounen","MyheroAcademia");
    A1.display_name();
    A1.animetype();
    A1.show_genre();

    return 0;
}