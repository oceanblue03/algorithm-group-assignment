#include <iostream>
#include "LibraryUserPanel.h"
using namespace std;

int main() {
    Books library[5];
    f.open("books.csv");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        library[i].ID = getCell(i + 1, 0);
        library[i].Title = getCell(i + 1, 1);
        library[i].author = getCell(i + 1, 2);
        library[i].category = getCell(i + 1, 3);
        library[i].availability = true;
    }
    
    displayLibrary(library);
    sortByTitle(library);
    displayLibrary(library);

    // LibraryUserPanel libraryUserPanel;
    // libraryUserPanel.menu();

    return 0;
}

// int searchBook(Book[] booksArray) {

// };

// void sortBook(Book** booksArray) {

// };