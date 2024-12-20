#include <iostream>
#include "admin.h"

using namespace std;

int main(){

    struct Books library[10];
    struct Transactions receipt[10];
    int count = 0;
    int bookID;
    int userID;
    Admin admin;
    int option;
    
    while (true){
        cout << "1. Add book" << endl;
        cout << "2. Search book" << endl;
        cout << "3. Edit book details" << endl;
        cout << "4. Delete book" << endl;
        cout << "5. View list of books (unsorted)" << endl;
        cout << "6. Sort and display books using bookID" << endl;
        cout << "7. Sort and display books using Title" << endl;
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

                cout << "Enter the book ID you wish to find: ";
                cin >> bookID;
                cin.ignore();

                admin.searchBookbyID(library , count , bookID);
                cout << "----------------------------------------" << endl;
                break;

            case 3 : 

                cout << "Enter the book ID you wish to edit: ";
                cin >> bookID;
                cin.ignore();

                admin.editBook(library , count , bookID);
                cout << "----------------------------------------" << endl;
                break;

            case 4 : 

                cout << "Enter the book ID that you wish to delete: ";
                cin >> bookID;
                cin.ignore();

                admin.deleteBook(library , &count , bookID);
                cout << "----------------------------------------" << endl;
                break;

            case 5 : 

                admin.viewUnsortedBooks(library , count);
                cout << "----------------------------------------" << endl;
                break;

            case 6 : 

                admin.sort_and_display_ID(library , count);
                cout << "----------------------------------------" << endl;
                break;

            case 7 : 

                admin.sort_and_display_Title(library , count);
                cout << "----------------------------------------" << endl;
                break;

            case 8 : 

                admin.viewReceipt(receipt , count);
                cout << "----------------------------------------" << endl;
                break;

            case 9 : 

                cout << "Please give me your student ID: ";
                cin >> userID;
                cin.ignore();

                admin.searchReceipt(receipt , count , userID);
                cout << "----------------------------------------" << endl;
                break;

            case 10 : 

                cout << "Going back to main menu" << endl;
                return 0;
        }
    }

    return 0;
}