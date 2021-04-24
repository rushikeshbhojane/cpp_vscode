#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>
using namespace std;
class Book
{
    private:
        /* data */
    public:
        char bookName[80];
        char author[80];
        Book(char _bookName[], char _author[]);
        ~Book();
};

Book::Book(char _bookName[], char _author[])
{
    strcpy(bookName, _bookName);
    strcpy(author, _author);
}

Book::~Book()
{
}

bool operator<(const Book &b1, const Book &b2){
    if (strcmp(b1.author, b2.author) > 0) {
            return true;
        } else if (strcmp(b1.author, b2.author) < 0) {
            return false;
        }
        if (strcmp(b1.bookName, b2.bookName) > 0) {
            return true;
        } else if (strcmp(b1.bookName, b2.bookName) < 0) {
            return false;
        }
        return false;
}

class compareBooks {
    public:
    bool operator() (Book& b1, Book& b2) {
        if (strcmp(b1.author, b2.author) > 0) {
            return true;
        } else if (strcmp(b1.author, b2.author) < 0) {
            return false;
        }
        if (strcmp(b1.bookName, b2.bookName) > 0) {
            return true;
        } else if (strcmp(b1.bookName, b2.bookName) < 0) {
            return false;
        }
        return false;
    }
};
int main() {
    // your code goes here
    vector <Book> shelve;
    vector <Book> borrowed;
    priority_queue<Book, vector<Book>, compareBooks> returned;
    string input;
    while (getline(cin, input))
    {
        /* code */    
        if (input == "END") {
            break;
        }
        char bookname[80], authorname[80];
        sscanf(input.c_str(), "\"%[^\"]\" by %[^\r\n]", bookname, authorname);
        shelve.push_back(Book(bookname, authorname));
    }
    sort(shelve.begin(), shelve.end(), greater<Book>());
    while (getline(cin, input))
    {
        /* code */    
        if (input == "END") {
            break;
        }
        if (input == "SHELVE") {
            while (!returned.empty())
            {
                Book top = returned.top();
                returned.pop();
                vector<Book>::iterator it = shelve.begin();
                int i = 0;
                for (; i < shelve.size(); i++)
                {
                    /* code */
                    if (strcmp(top.author, shelve[i].author) < 0) {
                        break;
                    } else if (
                        (strcmp(top.author, shelve[i].author) == 0) &&
                        strcmp(top.bookName, shelve[i].bookName) < 0) {
                        break;
                    }
                }

                if (i != 0) {
                    i--;
                    printf("Put \"%s\" after \"%s\"\n", top.bookName, shelve[i].bookName);
                } else {
                    printf("Put \"%s\" first\n", top.bookName);
                }
                shelve.insert(shelve.begin() + i, top);
            }
            printf("END\n");
        }
        char bookname[80], action[80], authorname[80];
        sscanf(input.c_str(), "%[^ \"] \"%[^\"\n\r]", action, bookname);
        
        if ( strcmp(action, "BORROW") == 0 ) {
            vector<Book>::iterator it = shelve.begin();
            while (it != shelve.end())
            {
                char loopBookName[80];
                if (strcmp(&(*it -> bookName), bookname) == 0) {
                    break;
                }
                ++it;
            }
            if (it != shelve.end()) {
                borrowed.push_back(Book(&(*it -> bookName)
                                            , &(*it -> author)));
                shelve.erase(it);
            }
        }

        if ( strcmp(action, "RETURN") == 0 ) {
            vector<Book>::iterator it = borrowed.begin();
            while (it != borrowed.end())
            {
                if (strcmp(&(*it -> bookName), bookname) == 0) {
                    break;
                }
                ++it;
            }
            if (it != shelve.end()) {
                returned.push(Book(&(*it -> bookName)
                                            , &(*it -> author)));
                borrowed.erase(it);
            }
        }
    }
    return 0;
}