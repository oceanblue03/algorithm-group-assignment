#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "UserLogin.h"
#include "ErrorHandleInput.h"
#include "LibraryUserPanel.h"
using namespace std;


int main(){
    cout << "Welcome to the Library Management System!" << endl;
    string filename = "users.csv";
    string username, password;
    vector<User> users = readUsersFromCSV(filename);
    while(true){
        cout << endl;
        int userInput = getOptionInput(3, "what you want to do?\n1. login as admin\n2. login as user\n3. exit\nEnter: ");
        if(userInput == 3){
            return 0 ;
        }else{
            username = getStringInputWithSpaces("Enter username: ");

            password = getStringInputWithSpaces("Enter password: ");

            User* loggedInUser = validateLogin(users, username, password);

            if (loggedInUser) {
                cout << "Login successful!" << endl;
                cout << "Username: " << loggedInUser->username << endl;
                cout << "Role: " << loggedInUser->role << endl;

                if (loggedInUser->role == "admin") {
                    adminMenu();
                } else if (loggedInUser->role == "user") {
                    LibraryUserPanel libraryUserPanel;
                    libraryUserPanel.user = *loggedInUser;
                    libraryUserPanel.setupLibrary();
                    libraryUserPanel.menu();
                } else {
                    cout << "Unknown role: " << loggedInUser->role << endl;
                }

                delete loggedInUser;
            } else {
                cout << "Invalid username or password!" << endl;
            }

        }
    }
}