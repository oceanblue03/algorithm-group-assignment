#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//struct for Books
struct Books{
    int ID;
    string Title;
    string author;
    string category;
    string availability;
};

//struct for Transactions
struct Transactions{
    int receiptNumber;
    int bookID;
    string userID;
    string date;
};

struct User {
    string username;
    string password;
    string role;
    int id;
};

bool compareStr(string a, string b);
void sort(string library[]);
string getCell(int row, int col);

const int ARRAY_SIZE = 5;
ifstream f;

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

void setupLibrary(Books library[]) {
            f.open("books.csv");
            for (int i = 0; i < ARRAY_SIZE; i++) {
                library[i].ID = stoi(getCell(i + 1, 0));
                library[i].Title = getCell(i + 1, 1);
                library[i].author = getCell(i + 1, 2);
                library[i].category = getCell(i + 1, 3);
                library[i].availability = true;
            }
        }

void displayTransaction(Transactions transaction) {
    cout << "book ID: " << transaction.bookID << endl;
    cout << "borrow date: " << transaction.date << endl;
    cout << "receipt number: " << transaction.receiptNumber << endl;
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

int binarySearchBooks(struct Books books[] , int low , int high , int ID){

    while(low <= high){

        int mid = (low + high) / 2;

        if(books[mid].ID == ID){
            return mid;
        }else if(books[mid].ID > ID){
            return binarySearchBooks(books , low , mid - 1 , ID);
        }else{
            return binarySearchBooks(books , mid + 1 , high , ID);
        }
    }

    return -1;
}

void searchBookbyID (struct Books books[] , int bookCount , int ID){

    int bookIndex = binarySearchBooks(books , 0 , bookCount - 1 , ID);

    if(bookIndex != -1){
        cout << "Book found: " << books[bookIndex].Title << " by " << books[bookIndex].author << endl;
    }else{
        cout << "Book with ID " << ID << " not found." << endl;
    }
}

bool isSubstring(string str1, string str2) {
    for (int i = 0; i < str1.length(); i++) {
        int j = 0;
        while (str1[i + j] == str2[j]) {
            j++;
            if (j == str2.length()) {
                return true;
            }
        }
    }

    return false;
}