#include <iostream>
#include "LibraryUserPanel.h"
using namespace std;

int main() {
    // Books library[5];
    // setupLibrary(library);
    // displayLibrary(library);

    LibraryUserPanel libraryUserPanel;
    libraryUserPanel.setupLibrary();
    libraryUserPanel.menu();

    return 0;
}