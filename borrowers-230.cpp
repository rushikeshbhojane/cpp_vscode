#include <iostream>
#include <string>
#include <cstring>
#include <memory>
#include <algorithm>
#include <sstream>
#include <regex>
using namespace std;

struct Storage {
    char book[80];
    char author[80];
    Storage* next;
    Storage (char bookInp[], char authorInp[]) {
        strcpy(book, bookInp);
        strcpy(author, authorInp);
        next = NULL;
    }
};

void insertIntoList(struct Storage *listStart,
            char book[], char author[],
            bool = false);

void insertIntoList(struct Storage *listStart,
            char book[], char author[],
            bool printMessage) {
        struct Storage *listStartIterator = listStart
                    ,*previous = NULL, *borrowedBook = new Storage(book, author);
        while (listStartIterator != NULL)
        {
            /* code */
            if (strcmp(listStartIterator -> author, author) > 0 || 
                (strcmp(listStartIterator -> author, author) ==  0
                 && strcmp(listStartIterator -> book, book) > 0)) {
                    if (printMessage) {
                        printf("put %s after %s\n", listStartIterator -> book, previous -> book);
                    }
                    borrowedBook -> next = previous -> next;
                    previous -> next = borrowedBook;
                break;
            }
            listStartIterator =  listStartIterator -> next;
            previous = listStartIterator;
        }

        if (listStartIterator == NULL) {
            if (previous == NULL && listStart == NULL) {
                listStart = borrowedBook;
                if (printMessage) {
                    printf("put %s first\n", listStart -> book);
                }
            } else {
                if (previous != NULL) {
                    if (printMessage) {
                        printf("put %s after %s\n", borrowedBook -> book, previous -> book);
                    }
                    previous -> next = borrowedBook;
                }
            }
        }
                
    }

struct Storage* removeFromList(struct Storage *listStart, char author[]) {
    struct Storage *listStartIterator = listStart
                    ,*previous = NULL;
    while (listStartIterator != NULL)
        {
            /* code */
            if (strcmp(listStartIterator -> author, author) == 0 ) {
                    if (previous != NULL) {
                        previous -> next = listStartIterator -> next;
                    } else {
                        listStart = listStartIterator -> next;
                    }
                break;
            }
            listStartIterator =  listStartIterator -> next;
            previous = listStartIterator;
        }
    return listStartIterator;
}

struct Storage *bookListStart = NULL;
struct Storage* bookListBorrowedStart =  NULL;
struct Storage* bookListReturnedStart = NULL;
int main() {
    // your code goes here
    string input;
    struct Storage*bookListStartIterator = NULL;
    char book[80], author[80];
    while(getline(cin, input))  {
        if (input == "END") break;
        sscanf(input.c_str() ,"\"%[^\"]\" by %[^\n\r]", book, author);
        if (bookListStartIterator == NULL)
        {
            bookListStartIterator = new Storage(book, author);
            bookListStart = bookListStartIterator;
        } else if (bookListStartIterator -> next == NULL) {
            bookListStartIterator -> next = new Storage(book, author);
            bookListStartIterator = bookListStartIterator -> next;
        }
    }
    while(getline(cin, input))  {
        if (input == "END") break;
        if (input == "SHELVE") {
            Storage* bls = bookListReturnedStart;
            while (bls != NULL)
            {
                bls = bls -> next;
                insertIntoList(bookListStart, bls -> book , bls -> author, true);
            }
            bookListReturnedStart = NULL;
            continue;
        }
        char action[20], book[80];
        sscanf(input.c_str() ,"%[^ \"] \"%[^\"\n\r]", action, book);
        cout << action << "\n";
        if ( strcmp(action, "BORROW") == 0 )  {
            struct Storage *bookListStartTemp = bookListStart, *previous = NULL;
            while (bookListStartTemp != NULL)
            {
                if (strcmp(book, bookListStartTemp -> book) == 0) {
                    if (bookListBorrowedStart != NULL) {
                        insertIntoList(bookListBorrowedStart,
                                bookListStartTemp -> book, bookListStartTemp -> author );
                    } else {
                        bookListBorrowedStart = new 
                                                Storage(bookListStartTemp -> book, bookListStartTemp -> author);
                    }
                    if (previous != NULL) {
                        previous -> next = bookListStartTemp -> next;
                    } else {
                        bookListStart = bookListStart -> next;                        
                    }
                    break;
                }
                previous = bookListStartTemp;
                bookListStartTemp = bookListStartTemp -> next;
            }
            
        }
        if ( strcmp(action, "RETURN") == 0 )  {
            struct Storage* returnedBook = removeFromList(bookListBorrowedStart, book);
            insertIntoList(bookListBorrowedStart, returnedBook -> book, returnedBook -> author);
        }
    }

    return 0;
}
