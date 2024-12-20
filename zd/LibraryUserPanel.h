#pragma once


#include <iostream>
#include "algorithms.h"
#include "UserLogin.h"
#include "ErrorHandleInput.h"

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

        void menu(int* transactionCount, int* bookCount) {
            *transactionCount = transactionArrayCounter;
            cout << "\nwhat would you like to do?\n";
            cout << "1. search for books\n";
            cout << "2. borrow books\n";
            cout << "3. display all books\n";
            cout << "4. view transaction history\n";
            cout << "5. exit the User Panel\n";
            userInput =  getOptionInput(5,"Enter: ");

            switch (userInput) {
                case 1:
                    searchBooks();
                    menu(transactionCount, bookCount);
                    break;
                case 2:
                    borrowBooks();
                    menu(transactionCount, bookCount);
                    break;
                case 3:
                    displayLibrary(bookCount);
                    menu(transactionCount, bookCount);
                    break;
                case 4:
                    viewTransactionHistory();
                    menu(transactionCount, bookCount);
                    break;
                case 5:
                    *transactionCount = transactionArrayCounter;
                    return;
                    break;
                default:
                    handleError();
                    menu(transactionCount, bookCount);
            }
            *transactionCount = transactionArrayCounter;
        }

        void setupLibrary(int* count) {
            f.open("books.csv");
            * count = stoi(getCell(0, 5));
            for (int i = 0; i < *count; i++) {
                library[i].ID = stoi(getCell(i + 1, 0));
                library[i].Title = getCell(i + 1, 1);
                library[i].author = getCell(i + 1, 2);
                library[i].category = getCell(i + 1, 3);
                if(stoi(getCell(i + 1, 4)) == 1){
                    library[i].availability = "available";
                }else{
                    library[i].availability = "unavailable";
                }
            }
            f.close();
        }

        void searchBooks() {
            searchInput =  getStringInputWithSpaces("please enter the key word: ");

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

            userInput =  getOptionInput(2,"Enter: ");
            switch (userInput) {
                case 1:
                    borrowBooks();
                    break;
                case 2:
                    return;
                    break;
                default:
                    handleError();
            }
        }

        void borrowBooks() {

            userInput =  getIntegerInput("please enter the id of the book you want to borrow: ");

            Books borrowedBook;
            bool bookExist = false;
            for (int i = 0; i < ARRAY_SIZE; i++) {
                if (userInput == library[i].ID) {
                    borrowedBook = library[i];
                    bookExist = true;
                }
            }
            if (!bookExist){
                cout << "Book Id does not exist do you want to enter the id again?\n1. yes\n2. no\n";
                userInput =  getOptionInput(2,"Enter: ");
                switch (userInput) {
                case 1:
                    borrowBooks();
                    break;
                case 2:
                    return;
                    break;
                default:
                    handleError();

                }
            return;

            }

            if (borrowedBook.availability == "unavailable"){
                cout << "The Book is unavailable do you want to enter the id again?\n1. yes\2. no\n";
                userInput =  getOptionInput(2,"Enter: ");
                switch (userInput) {
                case 1:
                    borrowBooks();
                    break;
                case 2:
                    return;
                    break;
                default:
                    handleError();

                }
            return;

            }
            

            cout << "book details:\n";
            cout << "ID: " << borrowedBook.ID << endl;
            cout << "Title: " << borrowedBook.Title << endl;
            cout << "author: " << borrowedBook.author << endl;
            cout << "category: " << borrowedBook.category << endl;

            cout << "are you sure you want to borrow?\n1. yes\n2. no\n ";
            userInput =  getOptionInput(2,"Enter: ");
            switch (userInput) {
                case 1:
                    break;
                case 2:
                    return;
                    break;
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
            userInput =  getOptionInput(2,"Enter: ");
            switch (userInput) {
                case 1:
                    borrowBooks();
                    break;
                case 2:
                    return;
                    break;
                default:
                    handleError();
            }
        }

        void displayLibrary(int* count) {
            for (int i = 0; i < *count; i++) {
                cout << "\nBook " << i + 1 << ": \n";
                cout << "ID: " << library[i].ID << endl;
                cout << "Title: " << library[i].Title << endl;
                cout << "author: " << library[i].author << endl;
                cout << "category: " << library[i].category << endl;
                cout << "availability: " << library[i].availability << endl << endl;
            }
        }

        void viewTransactionHistory() {
            cout << "\n";
            for (int i = 0; i < transactionArrayCounter; i++) {
                displayTransaction(transactionArray[i]);
                cout << "\n";
            }
        }

        void handleError() {

            return;
        }
};

