#include <iostream>
#include "admin.h"

using namespace std;

int main(){

    struct Books library[10];
    struct Transactions transaction[10];
    int count = 0;
    int ID;
    string username = "Hi";
    string password = "bye";
    Admin admin;
    if(!admin.authentication(&username , &password)){
        return 1;
    }

    int option;
    
    while (true){
        cout << "1. Add book" << endl;
        cout << "2. Search book" << endl;
        cout << "3. Edit book details" << endl;
        cout << "4. Delete book" << endl;
        cout << "5. View list of books (unsorted)" << endl;
        cout << "6. Sort books" << endl;
        cout << "7. Display books" << endl;
        cout << "8. View transaction receipt" << endl;
        cout << "9. Search transaction receipt" << endl;
        cout << "10. Exit" << endl;
        cout << "Choose an option: ";

        cin >> option;


        switch(option){
            case 1 : 
                admin.addBook(library , &count);
                cout << "----------------------------------------" << endl;
                break;

            case 2 : 
                admin.searchBookbyID(library , count , ID);
                cout << "----------------------------------------" << endl;
                break;

            case 3 : 

                cout << "Enter the book ID you wish to edit: ";
                cin >> ID;
                cin.ignore();

                admin.editBook(library , count , ID);
                cout << "----------------------------------------" << endl;
                break;

            case 4 : 
                admin.deleteBook(library , &count , ID);
                cout << "----------------------------------------" << endl;
                break;

            case 5 : 
                admin.viewUnsortedBooks(library , count);
                cout << "----------------------------------------" << endl;
                break;

            case 6 : 
                admin.sortBooks(library , count);
                cout << "----------------------------------------" << endl;
                break;

            case 7 : 
                admin.displayBooks(library , count);
                cout << "----------------------------------------" << endl;
                break;

            case 8 : 
                admin.viewReceipt(transaction , count);
                cout << "----------------------------------------" << endl;
                break;

            case 9 : 
                admin.searchReceipt(transaction , count);
                cout << "----------------------------------------" << endl;
                break;

            case 10 : 
                cout << "Going back to main menu" << endl;
                return 0;
        }
    }

    return 0;
}