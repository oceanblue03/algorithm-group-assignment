#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

bool compareStr(string a, string b);
void sort(string library[]);
string getCell(int row, int col);

const int ARRAY_SIZE = 5;
ifstream f;

struct Books{
    string ID;
    string Title;
    string author;
    string category;
    bool availability;
};

void sortByTitle(Books library[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE - 1; j++) {
            if (!compareStr(library[j].Title, library[j + 1].Title)) {
                Books t = library[j];
                library[j] = library[j + 1];
                library[j + 1] = t;
            }
        }
    }
}

bool compareStr(string a, string b) { // true if a < b
    int counter = 0;
    while (true) {
        if (int(tolower(a[counter])) < int(tolower(b[counter]))) {
            return true;
        }

        if (int(tolower(a[counter])) > int(tolower(b[counter]))) {
            return false;
        }

        counter++;
    }
}

void displayLibrary(Books library[]) {
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        cout << "Book " << i + 1 << ": \n";
        cout << "ID: " << library[i].ID << endl;
        cout << "Title: " << library[i].Title << endl;
        cout << "author: " << library[i].author << endl;
        cout << "category: " << library[i].category << endl;
        cout << "availability: " << library[i].availability << endl << endl;
    }
    
}

string getCell(int row, int col) {
    string a;
    string b;
    
    for (int i = 0; i < row + 1; i++) {
        getline(f, a);
    }
    
    stringstream ss(a);

    for (int i = 0; i < col + 1; i++) {
        getline(ss, b, ',');
    }

    f.clear();
    f.seekg(0);

    return b;
}
