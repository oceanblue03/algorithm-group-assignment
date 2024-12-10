#include <iostream>
using namespace std;

class LibraryUserPanel {
    public:
        int userInput;
        string searchInput;

        LibraryUserPanel() {}

        void menu() {
            cout << "what would you like to do?\n";
            cout << "1. search for books\n";
            cout << "2. borrow books\n";
            cout << "3. view transaction history\n";

            cin >> userInput;
            switch (userInput) {
                case 1:
                    searchBooks();
                    break;
                case 2:
                    borrowBooks();
                    break;
                case 3:
                    viewTransactionHistory();
                    break;
                default:
                    handleError();
                    break;
            }
        }

        void searchBooks() {
            cout << "please enter the key word: ";
            cin >> searchInput;

            menu();
        }

        void borrowBooks() {
            searchBooks();

            menu();
        }

        void viewTransactionHistory() {

            menu();
        }

        void handleError() {

            menu();
        }
};

