#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

string getStringInputWithSpaces(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

int getOptionInput(int n, const string& prompt) {
    string input;
    int option;
    while (true) {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);
        if (ss >> option && ss.eof() && option >= 1 && option <= n) {
            return option;
        } else {
            cout << "Invalid input, please enter a number between 1 and " << n << "!" << endl;
        }
    }
}

int getIntegerInput(const string& prompt) {
    string input;
    int value;
    while (true) {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);
        if (ss >> value && ss.eof()) {
            return value;
        } else {
            cout << "Invalid input, please enter an integer!" << endl;
        }
    }
}

double getDoubleInput(const string& prompt) {
    string input;
    double value;
    while (true) {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);
        if (ss >> value && ss.eof()) {
            return value;
        } else {
            cout << "Invalid input, please enter a floating-point number!" << endl;
        }
    }
}


