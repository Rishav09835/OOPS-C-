#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
using namespace std;

class Book
{
private:
    int bookid;
    char title[100];
    float price;
public:
    Book(){
        bookid = 0;
        strcpy(title,"none");
        price = 0;
    }
    void getBookDetails(){
        cout<<"Enter Bookid : ";
        cin>>bookid;
        cin.ignore(); //ignore leftover new line.
        cout<<"Enter Title : ";
        cin.getline(title,100);
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

    void viewAllBooks(){
        ifstream fin;
        fin.open("books.txt", ios::in|ios::binary);
        if(!fin)
            cout<<"\n file not found";
        else{
            fin.read((char*)this, sizeof(*this));
            while(!fin.eof()){
            showBookDetails();
            fin.read((char*)this, sizeof(*this));
            }
            fin.close();
        }
    }
    void searchBook(const char * t){
        int flag = 0;
        ifstream fin;
        fin.open("books.txt",ios::in|ios::binary);
        if(!fin)
            cout<<"\n File not found";
        else{
            fin.read((char *)this, sizeof(*this));
            while (!fin.eof())
            {
                if(!strcmp(t,this->title))
                {    flag = 1;
                    showBookDetails();
                }
                fin.read((char*)this, sizeof(*this));
            }
            if(flag == 0) cout<<"Record not found..";
            fin.close();
            
        }
    }
    void deleteBook(const char* t){
        ifstream fin;
        ofstream fout;
        fin.open("books.txt",ios::in|ios::binary);
        if(!fin) cout<<"\nfile not found...";
        else{
            fout.open("temp.txt",ios::out|ios::binary);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof()){
                if(strcmp(t,this->title)) //0 if equal else other values.
                    fout.write((char*)this,sizeof(*this));
                fin.read((char*)this, sizeof(*this));
            }
            fin.close();
            fout.close();
            remove("books.txt");
            rename("temp.txt","books.txt");
        }
    }
};

int main(){
    Book b1;
    b1.viewAllBooks();
    b1.deleteBook("Attitude is king");
    b1.viewAllBooks();
}