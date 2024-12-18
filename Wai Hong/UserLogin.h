#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct User {
    string username;
    string password;
    string role;
};

vector<User> readUsersFromCSV(const string& filename) {
    vector<User> users;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string username, password, role;

        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, role, ',');

        users.push_back({username, password, role});
    }
    file.close();
    return users;
}

User* validateLogin(const vector<User>& users, const string& username, const string& password) {
    for (auto& user : users) {
        if (user.username == username && user.password == password) {
            return new User(user);
        }
    }
    return nullptr;
}

void adminMenu() {
    cout << "Welcome, Admin!" << endl;
    cout << "1." << endl;
    cout << "2." << endl;
    cout << "3. Exit" << endl;
}

void userMenu() {
    cout << "Welcome, User!" << endl;
    cout << "1." << endl;
    cout << "2." << endl;
    cout << "3. Exit" << endl;
}


