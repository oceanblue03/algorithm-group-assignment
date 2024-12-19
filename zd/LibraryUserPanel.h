#include <iostream>
#include "algorithms.h"

using namespace std;

class LibraryUserPanel {
    public:
        int userInput;
        string searchInput;
        User user;
        Books library[ARRAY_SIZE];
        Transactions transactionArray[ARRAY_SIZE];
        int transactionArrayCounter = 0;

        LibraryUserPanel() {}

        void menu() {
            cout << "what would you like to do?\n";
            cout << "1. search for books\n";
            cout << "2. borrow books\n";
            cout << "3. display all books\n";
            cout << "4. view transaction history\n";

            cin >> userInput;
            switch (userInput) {
                case 1:
                    searchBooks();
                    menu();
                case 2:
                    borrowBooks();
                    menu();
                case 3:
                    displayLibrary();
                    menu();
                case 4:
                    viewTransactionHistory();
                    menu();
                default:
                    handleError();
                    menu();
            }
        }

        void setupLibrary() {
            f.open("books.csv");
            for (int i = 0; i < ARRAY_SIZE; i++) {
                library[i].ID = stoi(getCell(i + 1, 0));
                library[i].Title = getCell(i + 1, 1);
                library[i].author = getCell(i + 1, 2);
                library[i].category = getCell(i + 1, 3);
                library[i].availability = true;
            }
        }

        void searchBooks() {
            cout << "please enter the key word: ";
            cin >> searchInput;

            cout << "\nresults:\n";
            for (int i = 0; i < ARRAY_SIZE; i++) {
                if (isSubstring(library[i].Title, searchInput)) {
                    cout << "Book " << i + 1 << ": \n";
                    cout << "ID: " << library[i].ID << endl;
                    cout << "Title: " << library[i].Title << endl;
                    cout << "author: " << library[i].author << endl;
                    cout << "category: " << library[i].category << endl;
                    cout << "availability: " << library[i].availability << endl << endl;
                }       
            }

            cout << "do you want to borrow any books?\n1. yes\n2. no\n ";
            cin >> userInput;
            switch (userInput) {
                case 1:
                    borrowBooks();
                case 2:
                    menu();
                default:
                    handleError();
            }
        }

        void borrowBooks() {
            cout << "please enter the id of the book you want to borrow: ";
            cin >> userInput;

            Books borrowedBook;
            for (int i = 0; i < ARRAY_SIZE; i++) {
                if (userInput == library[i].ID) {
                    borrowedBook = library[i];
                }
            }

            cout << "book details:\n";
            cout << "ID: " << borrowedBook.ID << endl;
            cout << "Title: " << borrowedBook.Title << endl;
            cout << "author: " << borrowedBook.author << endl;
            cout << "category: " << borrowedBook.category << endl;

            cout << "are you sure you want to borrow?\n1. yes\n2. no\n ";
            cin >> userInput;
            switch (userInput) {
                case 1:
                    break;
                case 2:
                    menu();
                default:
                    handleError();
            }

            Transactions t;
            t.bookID = borrowedBook.ID;
            t.date = "18/12/2024";
            srand(time(0));
            int randomNum = rand();
            t.receiptNumber = randomNum;
            t.userID = user.id;
            transactionArray[transactionArrayCounter] = t;
            transactionArrayCounter++;

            cout << "transaction successful! do you want to borrow more books?\n1. yes\n2. no\n ";
            cin >> userInput;
            switch (userInput) {
                case 1:
                    borrowBooks();
                case 2:
                    menu();
                default:
                    handleError();
            }

            menu();
        }

        void displayLibrary() {
            for (int i = 0; i < ARRAY_SIZE; i++) {
                cout << "\nBook " << i + 1 << ": \n";
                cout << "ID: " << library[i].ID << endl;
                cout << "Title: " << library[i].Title << endl;
                cout << "author: " << library[i].author << endl;
                cout << "category: " << library[i].category << endl;
                cout << "availability: " << library[i].availability << endl << endl;
            }

            menu();
        }

        void viewTransactionHistory() {
            cout << "\n";
            for (int i = 0; i < transactionArrayCounter; i++) {
                displayTransaction(transactionArray[i]);
                cout << "\n";
            }

            menu();
        }

        void handleError() {

            menu();
        }
};

