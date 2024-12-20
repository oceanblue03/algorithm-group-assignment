#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "UserLogin.h"
#include "ErrorHandleInput.h"
#include "LibraryUserPanel.h"
#include "admin.h"
using namespace std;


int main(){
    cout << "Welcome to the Library Management System!" << endl;
    const int max_attempts = 3;
    string filename = "users.csv";
    string username, password;
    cout << "1" << endl;
    vector<User> users = readUsersFromCSV(filename);
    cout << "2" << endl;
    int bookCount = 5;
    int transactionCount = 0;
    LibraryUserPanel libraryUserPanel;
    cout << "3" << endl;
    libraryUserPanel.setupLibrary(bookCount);
    cout << "4" << endl;


    struct Books* library = libraryUserPanel.library;
    cout << "6" << endl;
    struct Transactions* receipt = libraryUserPanel.transactionArray;
    cout << "7" << endl;

    while(true){
        cout << endl;
        int userInput = getOptionInput(3, "what you want to do?\n1. login as admin\n2. login as user\n3. exit\nEnter: ");
        if(userInput == 3){
            return 0 ;
        }else{
            int attempts = 0;
            while (true)
            {
                if (attempts >= max_attempts){
                    cout << "Too many failed attempts. Exiting...." << endl;
                    return -1;
                }
                attempts ++;
                username = getStringInputWithSpaces("Enter username: ");

                password = getStringInputWithSpaces("Enter password: ");

                User* loggedInUser = validateLogin(users, username, password);

                if (loggedInUser) {
                    cout << "Login successful!" << endl;
                    cout << "Username: " << loggedInUser->username << endl;
                    cout << "Role: " << loggedInUser->role << endl;

                    if (loggedInUser->role == "admin") {

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

                                    admin.addBook(library , &bookCount);
                                    cout << "----------------------------------------" << endl;
                                    break;

                                case 2 : 

                                    cout << "Enter the book ID you wish to find: ";
                                    cin >> bookID;
                                    cin.ignore();

                                    admin.searchBookbyID(library , bookCount , bookID);
                                    cout << "----------------------------------------" << endl;
                                    break;

                                case 3 : 

                                    cout << "Enter the book ID you wish to edit: ";
                                    cin >> bookID;
                                    cin.ignore();

                                    admin.editBook(library , bookCount , bookID);
                                    cout << "----------------------------------------" << endl;
                                    break;

                                case 4 : 

                                    cout << "Enter the book ID that you wish to delete: ";
                                    cin >> bookID;
                                    cin.ignore();

                                    admin.deleteBook(library , &bookCount , bookID);
                                    cout << "----------------------------------------" << endl;
                                    break;

                                case 5 : 

                                    admin.viewUnsortedBooks(library , bookCount);
                                    cout << "----------------------------------------" << endl;
                                    break;

                                case 6 : 

                                    admin.sort_and_display_ID(library , bookCount);
                                    cout << "----------------------------------------" << endl;
                                    break;

                                case 7 : 

                                    admin.sort_and_display_Title(library , bookCount);
                                    cout << "----------------------------------------" << endl;
                                    break;

                                case 8 : 

                                    admin.viewReceipt(receipt , transactionCount);
                                    cout << "----------------------------------------" << endl;
                                    break;

                                case 9 : 

                                    cout << "Please give me your student ID: ";
                                    cin >> userID;
                                    cin.ignore();

                                    admin.searchReceipt(receipt , transactionCount , userID);
                                    cout << "----------------------------------------" << endl;
                                    break;

                                case 10 : 

                                    cout << "Going back to main menu" << endl;
                                    break;
                            }
                            if(option == 10){
                                break;
                            }
                        }


                    } else if (loggedInUser->role == "user") {
                        libraryUserPanel.user = *loggedInUser;
                        libraryUserPanel.menu(&transactionCount, &bookCount);
                    } else {
                        cout << "Unknown role: " << loggedInUser->role << endl;
                    }
                    break;
                    delete loggedInUser;
                } else {
                    cout << "Invalid username or password!" << endl;
                    cout << (max_attempts - attempts) << " attempts remaining" << endl;
                }
            }
        }
    }
}