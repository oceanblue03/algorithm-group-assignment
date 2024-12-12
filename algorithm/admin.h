#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include <limits>

using namespace std;

//struct for Books
struct Books{
    int ID;
    string Title;
    string author;
    string category;
    string availability;
};

//struct for Transactions
struct Transactions{
    int receiptNumber;
    char userID [50];
    char details [200];
};

class Admin{
    public:
    bool authentication(const string* username , const string* password){
    
        const int max_attempts = 3;
        int attempts = 0;
        string user , pass;

        while (attempts < max_attempts){
            cout << "Enter your username: ";
            getline(cin , user);

            if(user == *username){
                cout << "Enter your password: ";
                getline(cin , pass);

                if(pass == *password){
                    cout << "Welcome" << endl;
                    return true;
                }else{
                    cout << "Incorrect password" << endl;
                }
            }else{
                cout << "Incorrect username" << endl;
            }

            attempts++;
            cout << (max_attempts - attempts) << " attempts remaining" << endl;
            cout << "Try again" << endl;
        }

        cout << "Too many failed attempts. Exiting...." << endl;
        return false;
    }

    //Books management
    void addBook (struct Books books[] , int* bookCount){
        
        Books newbook;

        cout << "Enter the ID of the book: ";
        cin >> newbook.ID;
        cin.ignore();
        cout << "Enter the book title: ";
        getline(cin , newbook.Title);
        cout << "Enter the author of the book: ";
        getline(cin , newbook.author);
        cout << "Enter the category of the book: ";
        getline(cin , newbook.category);
        cout << "Enter the availability of the book (0 - unavailable / 1 - available): ";
        getline(cin , newbook.availability);

        books[*bookCount] = newbook;
        (*bookCount)++;

        cout << "Books added successfully. " << endl;
    }

    int searchBookbyID (struct Books books[] , int bookCount , int ID){

        
        
        return ID;
    }

    void editBook (struct Books books[] , int bookCount , int ID){

        bool bookExist = false;

        for(int i  = 0 ; i < bookCount ; i++){
            if(books[i].ID == ID){
                bookExist = true;

                cout << "Enter the book title: ";
                getline(cin , books[i].Title);
                cout << "Enter the author of the book: ";
                getline(cin , books[i].author);
                cout << "Enter the category of the book: ";
                getline(cin , books[i].category);
                cout << "Enter the book availability (0 - unavailable / 1 - available): ";
                getline(cin , books[i].availability);

                if(books[i].availability == "0" || books[i].availability == "1"){
                    if(books[i].availability == "1"){
                        cout << "Availability: " << "available" << endl;
                    }else if(books[i].availability == "0"){
                        cout << "Availability: " << "unavailable" << endl;
                    }
                }else{
                    cout << "Invalid value. Keeping the previous value." << endl;
                }

                cout << "Book edited successfully" << endl;
                return;
            }
        }
        
        if(!bookExist){
            cout << "The book does not exist in this library." << endl;
        }
     
    }

    void deleteBook (struct Books books[] , int* bookCount , int ID){

    }

    void viewUnsortedBooks (const struct Books books[] , int bookCount){

        if(bookCount == 0){
            cout << "No books to display" << endl;
            return;
        }

        for(int i = 0 ; i < bookCount ; i++){
            cout << "Book " << i + 1 << endl;
            cout << "ID: " << books[i].ID << endl;
            cout << "Title: " << books[i].Title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Category: " << books[i].category << endl;
            if(books[i].availability == "1"){
                cout << "Availability: " << "available" << endl;
            }else if(books[i].availability == "0"){
                cout << "Availability: " << "unavailable" << endl;
            }
            cout << endl;
        }

    }

    void sortBooks (struct Books books[] , int bookCount){

    }

    void displayBooks (struct Books books[] , int bookCount){

    }

    //Transaction management
    void viewReceipt (struct Transactions transaction[] , int transactionCount){

    }

    int searchReceipt (struct Transactions transaction[] , int transactionCount){
        return 0;
    }

};

#endif // ADMIN_H