#include<bits/stdc++.h>
#include<conio.h>
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
    void updateBookRecord(const char* t){
        fstream file;
        file.open("books.txt",ios::in|ios::out|ios::ate|ios::binary);
        file.seekg(0);
        file.read((char*)this,sizeof(*this));
        while (!file.eof())
        {
            if(!strcmp(t,title)){
                getBookDetails();
                streampos pos = file.tellp();
                file.seekp(pos-sizeof(*this));
                file.write((char*)this, sizeof(*this));
            }
            file.read((char*)this,sizeof(*this));
        }
        file.close();

    }
};

int menu(){
    int choice;
    cout<<"\n Personal Book Management System";
    cout<<"\n1. Add Book Record";
    cout<<"\n2. View All Book Records";
    cout<<"\n3. Search Book Record";
    cout<<"\n4. Delete Book Record";
    cout<<"\n5. Update Book Record";
    cout<<"\n6. Exit";
    
    cout<<"\n\n Enter Your Choice : ";
    cin>>choice;
    cin.ignore();
    return choice;
}

int main(){
    Book b1;
    char title[100];
    while (1)
    {  system("cls");
        switch(menu())
        {
            case 1: 
                b1.getBookDetails();
                b1.storeBookDetails();
                cout<<"\nRecord Inserted Successfully"<<endl;
                break;
            case 2:
                b1.viewAllBooks();
                break;
            case 3:
                cout<<"Enter Book title to Search Book: ";
                cin.getline(title,100);
                b1.searchBook(title);
                break;
            case 4:
                cout<<"Enter Book title to Delete Book: ";
                cin.getline(title,100);
                b1.deleteBook(title);
                break;
            case 5:
                cout<<"Enter Book Title to update Book: ";
                cin.getline(title,100);
                b1.updateBookRecord(title);
                break;
            case 6:
                cout<<"\nThank you!!";
                exit(0);
            default:
                cout<<"\nInvalid choice ";

        }
        getch();
    }
    
}