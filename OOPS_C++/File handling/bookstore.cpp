#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Book
{
private:
    int bookid;
    string title;
    float price;
public:
    Book(){
        bookid = 0;
        title = "none";
        price = 0;
    }
    void getBookDetails(){
        cout<<"Enter Bookid : ";
        cin>>bookid;
        cin.ignore(); //ignore leftover new line.
        cout<<"Enter Title : ";
        getline(cin,title);
        cout<<"Enter price : ";
        cin>>price;
    }
    void showBookDetails(){
        cout<<"\nBook Details...";
        cout << "\nBook ID: " << bookid << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
    int storeBookDetails(){
        if(bookid==0 && price==0){
            cout<<"Can't Store details as Book data is not initialized";
            return 0;
        }
        ofstream fout;
        fout.open("books.txt",ios::app|ios::binary); //app->purana data stays, binary->text treatment no special meaning.
                //char type mein type cast karna padega kyu? socho socho. (inbuilt write mein char value hi jati hai)
        fout.write((char*)this,sizeof(*this)); //write-> to write in files, takes 2 argument= 1st data jis jagah present hai us ka address, 2nd kitna size ka data hai.
        fout.close();
        return 1;
    }
};

int main(){
    Book b1,b2;
    b1.getBookDetails();
    b1.showBookDetails();
    b1.storeBookDetails();
    b2.storeBookDetails();
}