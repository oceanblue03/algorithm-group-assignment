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
    vector<User> users = readUsersFromCSV(filename);
    int bookCount = 5;
    int transactionCount = 0;
    LibraryUserPanel libraryUserPanel;

    libraryUserPanel.setupLibrary(&bookCount);
    int studentId = 0;



    struct Books* library = libraryUserPanel.library;
    struct Transactions* receipt = libraryUserPanel.transactionArray;

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

                            option = getOptionInput(10, "Choose an option: ");

                            switch(option){
                                case 1 : 

                                    admin.addBook(library , &bookCount);
                                    cout << "----------------------------------------" << endl;
                                    break;

                                case 2 : 

                                    bookID =  getIntegerInput("Enter the book ID you wish to find: ");


                                    admin.searchBookbyID(library , bookCount , bookID);
                                    cout << "----------------------------------------" << endl;
                                    break;

                                case 3 : 


                                    bookID =  getIntegerInput("Enter the book ID you wish to edit: ");

                                    admin.editBook(library , bookCount , bookID);
                                    cout << "----------------------------------------" << endl;
                                    break;

                                case 4 : 

                                    bookID =  getIntegerInput("Enter the book ID you wish to delete: ");

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

                                    userID =  getIntegerInput("Please give me your student ID: ");

                                    admin.searchReceipt(receipt , transactionCount , userID);
                                    cout << "----------------------------------------" << endl;
                                    break;

                                case 10 : 

                                    cout << "Going back to main menu" << endl;
                                    break;
                            }
                            ofstream file("books.csv");

                            if (!file.is_open()) {
                                cerr << "Unable to open file: " << filename << endl;
                                return 0 ;
                            }

                            file << "id,title,author,category,availability,"<<bookCount<<"\n";
                            for(int i = 0; i < bookCount; i++){
                                file << library[i].ID << ",";
                                file << library[i].Title << ",";
                                file << library[i].author << ",";
                                file << library[i].category << ",";
                                if (library[i].availability == "available")
                                {
                                    file << "1\n";
                                }else{
                                    file << "0\n";
                                }
                                
                            }

                            file.close();
                            if(option == 10){
                                break;
                            }
                        }


                    } else if (loggedInUser->role == "user") {
                        studentId = getIntegerInput("Please enter your student id: ");
                        loggedInUser->id = studentId;
                        cout << loggedInUser->id ;
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