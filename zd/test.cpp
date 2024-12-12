#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

bool compareStr(string a, string b);
void sort(string arr1[]);
string getCell(int row, int col);

ifstream f;
const int ARRAY_SIZE = 5;

struct book{
    int a;
    int b;
};

int main()
{
    string a;
    f.open("books.csv");
    getline(f, a);
    cout << a << endl;
    f.clear();
    f.seekg(0);
    getline(f, a);
    cout << a << endl;
}

void sort(string arr1[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE - 1; j++) {
            if (!compareStr(arr1[j], arr1[j + 1])) {
                string t = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = t;
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

    return b;
}
