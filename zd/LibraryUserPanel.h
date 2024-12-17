#include <iostream>
#include "algorithms.h"
using namespace std;

class LibraryUserPanel {
    public:
        int userInput;
        string searchInput;
        Books library[ARRAY_SIZE];

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
                    break;
                case 2:
                    borrowBooks();
                    break;
                case 3:
                    displayLibrary();
                    break;
                case 4:
                    viewTransactionHistory();
                    break;
                default:
                    handleError();
                    break;
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

            menu();
        }

        void borrowBooks() {
            searchBooks();

            menu();
        }

        void displayLibrary() {
            for (int i = 0; i < ARRAY_SIZE; i++) {
                cout << "Book " << i + 1 << ": \n";
                cout << "ID: " << library[i].ID << endl;
                cout << "Title: " << library[i].Title << endl;
                cout << "author: " << library[i].author << endl;
                cout << "category: " << library[i].category << endl;
                cout << "availability: " << library[i].availability << endl << endl;
            }

            menu();
        }

        void viewTransactionHistory() {

            menu();
        }

        void handleError() {

            menu();
        }
};

