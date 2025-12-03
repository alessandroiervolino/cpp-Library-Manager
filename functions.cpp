#include "functions.h"
#include <iostream>
#include <limits>

void addBook(vector<Book> &books){
    system("cls");
    string t,a;
    cout << "Write the tittle of the new book" << endl;
    if (cin.peek() == '\n'){
        cin.ignore();
    } 
    getline(cin, t);
    cout << "Write the author of the new book" << endl;
    if (cin.peek() == '\n'){
        cin.ignore();
    } 
    getline(cin, a);
    Book newBook (t, a);
    books.push_back(newBook);
    cout << "Book added!" << endl;
}

void showBooks(const vector<Book> &books, string filter, string user){
    system("cls");
    if (books.empty()){
        cout << "There are no books" << endl;
        return;
    }
    for (int i=0; i < books.size(); i++){
        if (filter == "all"){
            if (books[i].getStatus() == "unavailable"){
                cout << "ID: " << books[i].getId() << "|" << "Tittle: " << books[i].getTittle() << "|" << "Author: " << books[i].getAuthor() << "|" << "Status: " << books[i].getStatus() << "|" << "Borrowed by: " << books[i].getUser() << endl;    
            }
            if (books[i].getStatus() == "available"){
                cout << "ID: " << books[i].getId() << "|" << "Tittle: " << books[i].getTittle() << "|" << "Author: " << books[i].getAuthor() << "|" << "Status: " << books[i].getStatus() << endl;
            }
        }
        if (filter == books[i].getStatus() && books[i].getStatus() == "unavailable" && books[i].getUser() == user){
            cout << "ID: " << books[i].getId() << "|" << "Tittle: " << books[i].getTittle() << "|" << "Author: " << books[i].getAuthor() << "|" << "Status: " << books[i].getStatus() << "|" << "Borrowed by: " << books[i].getUser() << endl;    
        }
        if (filter == books[i].getStatus() && books[i].getStatus() == "available"){
            cout << "ID: " << books[i].getId() << "|" << "Tittle: " << books[i].getTittle() << "|" << "Author: " << books[i].getAuthor() << "|" << "Status: " << books[i].getStatus() << endl;
        }
    }
    
}

void findBook(const vector<Book> &books){
    system("cls");
    if (books.empty()){
        cout << "There are no books" << endl;
        return;
    }
    string find;
    bool found = false;
    cout << "Write the tittle or the ID of the book you want to find: " << endl;
    if (cin.peek() == '\n'){
        cin.ignore();
    }
    getline(cin, find);
    for(int i = 0; i < books.size(); i++){
        cout << books[i].getTittle() << endl;
        if (find == books[i].getTittle()){
            cout << "Book found by tittle!" << endl;
            found = true;
            if(books[i].getStatus() == "unavailable"){
                cout << "ID: " << books[i].getId() << "|" << "Tittle: " << books[i].getTittle() << "|" << "Author: " << books[i].getAuthor() << "|" << "Status: " << books[i].getStatus() << "|" << "Borrowed by: " << books[i].getUser() << endl;    
            }
            if(books[i].getStatus() == "available"){
                cout << "Tittle: " << books[i].getTittle() << " Author: " << books[i].getAuthor() << " Status: " << books[i].getStatus() << endl;
            }
            return;
        }
        else{
            try
            {
                int id = stoi(find);
                for(int i = 0; i < books.size(); i++){
                    if(id == books[i].getId()){
                        found = true;
                        cout << "Book found by ID!" << endl;
                        cout << "Tittle: " << books[i].getTittle() << " Author: " << books[i].getAuthor() << " Status: " << books[i].getStatus() << endl;
                        return;
                    }
                }
            }
            catch(invalid_argument&)
            {
                
            }
        }
    }
    if (!found){
        cout << find << endl;

        cout << "No book found with this tittle or ID." << endl;
    }
}

void removeBook(vector<Book> &books){
    system("cls");
    if (books.empty()){
        cout << "There are no books" << endl;
        return;
    }
    int remove;
    showBooks(books);
    cout << "Which book do you want to remove from the library? (Write the ID):" << endl;
    cout << "0. I don't want to erase anything" << endl;
    cin >> remove;
    bool found = false;
    if (remove == 0){
            return;
    }
    for (int i = 0; i < books.size(); i++){
        if (remove == books[i].getId()){
            books.erase(books.begin() + i);
            found = true;
            cout << "Book removed!" << endl;
            return;
        }
    }
    if (!found){
        cout << "No book with that ID exists." << endl;
        return;
    }
}
void showUsers(const vector<User> &users){
    system("cls");
    if (users.empty()){
        cout << "There are no users registered" << endl;
        cout << "Please register a user" << endl;
        return;
    }
    for (int i = 0; i < users.size(); i++){
        cout << "ID: " << users[i].getId() << "|" << "Username: " << users[i].getUsername() << endl;
    }
}

void lendBook(vector<Book> &books, vector<User> &users){
    showUsers(users);
    if (users.empty()){
        return;
    }
    cout << "Which user is borrowing the book? (write the ID):" << endl;
    int borrower_id;
    bool found = false;
    string borrower;
    cin >> borrower_id;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a valid ID please" << endl;
        cin >> borrower_id;
    }
    for (int i = 0; i < users.size(); i++){
        if (borrower_id == users[i].getId()){
            found = true;
            borrower = users[i].getUsername();
        }
    }
    if (!found){
        cout << "No user with that ID exists" << endl;
    }
    showBooks(books, "available");//quiero mostrar solo los que estan en status == "available"
    int count = 0;
    for (int i = 0; i < books.size(); i++){
        if (books[i].getStatus() == "available"){
            count ++;
        }
    }
    if (count == 0){
        cout << "There are no books aviable right now" << endl;
        return;
    }
    cout << "0. I don't want to borrow anything" << endl;
    cout << "Which book do you want to borrow? (write the ID): " << endl;
    int lend;
    cin >> lend;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a valid ID please" << endl;
        cin >> lend;
    }
    if (lend == 0){
            return;
    }
    bool found1 = false;
    for (int i = 0; i < books.size(); i++){
        if (lend == books[i].getId() && books[i].getStatus() == "available"){
            books[i].setStatus("unavailable");
            books[i].setUser(borrower);
            cout << "Book lended!" << endl;
            found1 = true;
            return;            
        }
    }
    cout << "This book is unavailable" << endl;
    return;
    if (!found1){
        cout << "No book with that ID exists." << endl;
        return;
    } 
}

void returnBook(vector<Book> &books, const vector<User> users){
    showUsers(users);
    if (users.empty()){
        return;
    }
    cout << "Which user is returning the book? (write the ID):" << endl;
    int returner_id;
    bool found1 = false;
    string returner;
    cin >> returner_id;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a valid ID please" << endl;
        cin >> returner_id;
    }
    for (int i = 0; i < users.size(); i++){
        if (returner_id == users[i].getId()){
            found1 = true;
            returner = users[i].getUsername();
        }
    }
    if (!found1){
        cout << "No user with that ID exists" << endl;
    }
    system("cls");

    showBooks(books, "unavailable", returner);
    int count = 0;
    for (int i = 0; i < books.size(); i++){
        if (books[i].getUser() == returner){
            count ++;
        }
    }
    if (count == 0){
        cout << "This user does not have books to return" << endl;
        return;
    }
    cout << "0. I don't want to return anything" << endl;
    cout << "Which book do you want to return? (write the ID): " << endl;
    int ret;
    cin >> ret;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a valid ID please" << endl;
        cin >> ret;
    }
    if (ret == 0){
        return;
    }
    bool found = false;
    for (int i = 0; i < books.size(); i++){
        if (books[i].getId() == ret){
            found = true;
            books[i].setStatus("available");
            books[i].setUser(returner);
            cout << "Book returned!" << endl;
            return;
        }
    }
    if (!found){
        cout << "No book with that ID exists." << endl;
        return;
    }
}

void registerUser(vector<User> &users){
    system("cls");
    cout << "Creating new user..." << endl;
    cout << "Please set a username" << endl;
    string username;
    cin >> username;
    User newUser(username);
    users.push_back(newUser);
    cout << "User registered!" << endl;
}