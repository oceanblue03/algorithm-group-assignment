#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "UserLogin.h"
#include "ErrorHandleInput.h"

using namespace std;

int main() {
    string filename = "users.csv";
    vector<User> users = readUsersFromCSV(filename);

    cout << "Welcome to the Login System!" << endl;
    string username, password;

    username = getStringInputWithSpaces("Enter username: ");

    password = getStringInputWithSpaces("Enter password: ");

    User* loggedInUser = validateLogin(users, username, password);

    if (loggedInUser) {
        cout << "Login successful! Role: " << loggedInUser->role << endl;

        if (loggedInUser->role == "admin") {
            adminMenu();
        } else if (loggedInUser->role == "user") {
            userMenu();
        } else {
            cout << "Unknown role: " << loggedInUser->role << endl;
        }

        delete loggedInUser;
    } else {
        cout << "Invalid username or password!" << endl;
    }

    return 0;
}