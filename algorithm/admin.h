#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>

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

class Admin{
    public:
    //Books management
    void addBook (struct Books books[] , int* bookCount){
        
        Books newbook;

        cout << "Enter the ID of the book: ";
        cin >> newbook.ID;
        cin.ignore();

        for(int i = 0 ; i < *bookCount ; i++){
            if(books[i].ID == newbook.ID){
                cout << "Books with ID " << newbook.ID << " is already exist." << endl;
                return;
            }
        }
        
        cout << "Enter the book title: ";
        getline(cin , newbook.Title);
        cout << "Enter the author of the book: ";
        getline(cin , newbook.author);
        cout << "Enter the category of the book: ";
        getline(cin , newbook.category);
        cout << "Enter the availability of the book (0 - unavailable / 1 - available): ";
        getline(cin , newbook.availability);

        books[*bookCount] = newbook;
        (*bookCount)++; 

        cout << "Book added successfully." << endl;      
    }

    void searchBookbyID (struct Books books[] , int bookCount , int ID){

        int bookIndex = binarySearchBooks(books , 0 , bookCount - 1 , ID);

        if(bookIndex != -1){
            cout << "Book found: " << books[bookIndex].Title << " by " << books[bookIndex].author << endl;
        }else{
            cout << "Book with ID " << ID << " not found." << endl;
        }
    }

    void editBook (struct Books books[] , int bookCount , int ID){

        bool bookExist = false;

        for(int i  = 0 ; i < bookCount ; i++){
            if(books[i].ID == ID){
                bookExist = true;

                cout << "Enter the book title: ";
                getline(cin , books[i].Title);
                cout << "Enter the author of the book: ";
                getline(cin , books[i].author);
                cout << "Enter the category of the book: ";
                getline(cin , books[i].category);
                cout << "Enter the book availability (0 - unavailable / 1 - available): ";
                getline(cin , books[i].availability);

                if(books[i].availability == "0" || books[i].availability == "1"){
                    if(books[i].availability == "1"){
                        cout << "Availability: " << "available" << endl;
                    }else if(books[i].availability == "0"){
                        cout << "Availability: " << "unavailable" << endl;
                    }
                }else{
                    cout << "Invalid value. Keeping the previous value." << endl;
                }

                cout << "Book edited successfully" << endl;
                return;
            }
        }
        
        if(!bookExist){
            cout << "The book does not exist in this library." << endl;
        }
     
    }

    void deleteBook (struct Books books[] , int* bookCount , int ID){

        if(*bookCount != -1){

            for(int i = 0 ; i < *bookCount ; i++){
                if(books[i].ID == ID){
                    (*bookCount)--;

                    for(int j = i ; j < *bookCount ; j++){
                        books[j] = books[j + 1];
                    }

                    break;
                }
            }
        }else{
            cout << "Book with ID " << ID << " is not found." << endl;
        }

        cout << "Book with ID " << ID << " successfully deleted." << endl;
    }

    void viewUnsortedBooks (const struct Books books[] , int bookCount){

        if(bookCount == 0){
            cout << "No books to display" << endl;
            return;
        }

        for(int i = 0 ; i < bookCount ; i++){
            cout << "Book " << i + 1 << endl;
            cout << "ID: " << books[i].ID << endl;
            cout << "Title: " << books[i].Title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Category: " << books[i].category << endl;
            if(books[i].availability == "1"){
                cout << "Availability: " << "available" << endl;
            }else if(books[i].availability == "0"){
                cout << "Availability: " << "unavailable" << endl;
            }
            cout << endl;
        }

    }

    void sort_and_display_ID (struct Books books[] , int bookCount){

        mergeSort(books , 0 , bookCount - 1);
        cout << "The books are sorted in ascending order based on ID." << endl;

        for(int i = 0 ; i < bookCount ; i++){
            cout << books[i].ID << ": " << books[i].Title << " by " << books[i].author << endl;
        }

    }

    void sort_and_display_Title (struct Books books[] , int bookCount){

        bubbleSort(books , bookCount);
        cout << "The books are sorted lexicographically based on books' title." << endl;

        for(int i = 0 ; i < bookCount; i++){
            cout << "Book " << i + 1 << ": " << books[i].Title << " by " << books[i].author << " with ID " << books[i].ID << endl; 
        }

    }

    //Transaction management
    void viewReceipt (struct Transactions transaction[] , int transactionCount){

        if(transactionCount == 0){
            cout << "No transaction history." << endl;
            return;
        }
        
        selectionSort(transaction , transactionCount);

        for(int i = 0 ; i < transactionCount ; i++){
            cout << "Receipt Number: " << transaction[i].receiptNumber << endl;
            cout << "UserID: " << transaction[i].userID << endl;
            cout << "BookID: " << transaction[i].bookID << endl;
            cout << "Date: " << transaction[i].date << endl;
        }

    }

    void searchReceipt (struct Transactions transaction[] , int transactionCount , int userID){

        int userIndex = binarySearchReceipt(transaction , 0 , transactionCount - 1 , userID);

        if(userIndex != -1){
            cout << "Receipt found: " << transaction[userIndex].userID << endl;
            cout << "Date: " << transaction[userIndex].date << endl;
        }else{
            cout << "Receipt with this ID " << userID << " not found." << endl;
        }
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

    void merge(struct Books books[] , int left , int mid , int right){

        int n1 = mid - left + 1;
        int n2 = right - mid;

        Books* temp1 = new Books[n1];
        Books* temp2 = new Books[n2];

        for(int i = 0 ; i < n1 ; i++){
            temp1[i] = books[left + i];
        }
        for(int j = 0 ; j < n2 ; j++){
            temp2[j] = books[mid + 1 + j];
        }

        int i = 0 , j = 0 , k = left;
        while(i < n1 && j < n2){
            if(temp1[i].ID <= temp2[j].ID){
                books[k] = temp1[i];
                i++;
            }else{
                books[k] = temp2[j];
                j++;
            }
            k++;
        }

        while (i < n1){
            books[k] = temp1[i];
            i++ , k++;
        }

        while (j < n2){
            books[k] = temp2[j];
            j++ , k++;
        }
    }

    void mergeSort(struct Books books[] , int left , int right){

        if(left < right){
            int mid = (left + right) / 2;

            mergeSort(books , left , mid);
            mergeSort(books , mid + 1 , right);
            merge(books , left , mid , right);
        }    
    }

    void bubbleSort(struct Books books[] , int size){
        for(int i = 0 ; i < size - 1 ; i++){
            for(int j = 0 ; j < size - i - 1 ; j++){
                if(books[j].Title > books[j + 1].Title){
                    Books temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }              
            }
        }
    }

    void selectionSort(struct Transactions transaction[] , int size){
        for(int i = 0 ; i < size - 1 ; i++){           
            int minIndex = i;
            for(int j = i + 1 ; j < size ; j++){
                if(transaction[j].receiptNumber < transaction[minIndex].receiptNumber){
                    minIndex = j;
                }
            }

            if(!minIndex){
                Transactions temp = transaction[i];
                transaction[i] = transaction[minIndex];
                transaction[minIndex] = temp;
            }
        }
    }

    int binarySearchReceipt(struct Transactions transaction[] , int low , int high , int userID){

        while(low <= high){

            int mid = (low + high) / 2;

            if(transaction[mid].bookID == userID){
                return mid;
            }else if(transaction[mid].bookID > userID){
                return binarySearchReceipt(transaction , low , mid - 1 , userID);
            }else{
                return binarySearchReceipt(transaction , mid + 1 , high , userID);
            }
        }

        return -1;
    }
};

#endif // ADMIN_H