#include "book.h"
#include "user.h"
#include "functions.h"
#include <iostream>
#include <limits>

int main(){
    vector<Book> books;
    vector<User> users;
    int running = 1;
    int n;
    while(running){
        cout << "--- Library Manager ---" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Show all books" << endl;
        cout << "3. Find book (by id or title)" << endl;
        cout << "4. Remove book" << endl;
        cout << "5. Lend book (borrow)" << endl;
        cout << "6. Return book" << endl;
        cout << "7. Register user" << endl;
        cout << "8. Show users" << endl;
        cout << "9. Exit" << endl;
        cout << "SELECT AN OPTION:" << endl;

        cin >> n;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a number please" << "\n";
            cin >> n;
        }

        switch(n){
            case 1:
                addBook(books);
                system("pause");
                system("cls");
                break;
            case 2:
                showBooks(books);
                system("pause");
                system("cls");
                break;
            case 3:
                findBook(books);
                system("pause");
                system("cls");
                break;
            case 4:
                removeBook(books);
                system("pause");
                system("cls");
                break;
            case 5:
                lendBook(books, users);
                system("pause");
                system("cls");
                break;
            case 6:
                returnBook(books, users);
                system("pause");
                system("cls");
                break;
            case 7:
                registerUser(users);
                system("pause");
                system("cls");
                break;
            case 8:
                showUsers(users);
                system("pause");
                system("cls");
                break;
            case 9:
                cout << "Exiting..." << endl;
                return 0;
                break;
            default:
                cout << "This is not a valid option " << endl;
                break;
        }
    }
    return 0;
}
