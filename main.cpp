#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

class Book {
    private:
        string tittle, author, status, user;
        int id;
        static int nextId;

    public:
        Book(string _tittle, string _author): tittle(_tittle), author(_author){id = nextId ++; status = "available";/*autoincrementacion del id */} //constructor
        void setTittle(string tittle);
        void setAuthor(string author);
        void setStatus(string status);   
        void setUser(string user);
        string getTittle() const;
        string getAuthor() const;
        int getId() const;
        string getStatus() const;
        string getUser() const;
};

class User {
    private:
        string username;
        int userId;
        static int nextId;
    public:
        User(string _username): username(_username){userId = nextId ++;}
        void setUsername(string username);
        string getUsername() const;
        int getId() const;
};

int Book::nextId = 1;
int User::nextId = 1;

void Book::setTittle(string _tittle){
    tittle = _tittle;
}

void Book::setAuthor(string _author){
    author = _author;
}

void Book::setStatus(string _status){
    status = _status;
}

void Book::setUser(string _user){
    user = _user;
}

void User::setUsername(string _username){
    username = _username;
}

string Book::getTittle() const{
    return tittle;
}

string Book::getAuthor() const{
    return author;
}

int Book::getId() const{
    return id;
}

string Book::getStatus() const{
    return status;
}

string Book::getUser() const{
    return user;
}

string User::getUsername() const{
    return username;
}

int User::getId() const{
    return userId;
}

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

void showBooks(const vector<Book> &books, string filter = "all", string user = "all"){
    system("cls");
    if (books.empty()){
        cout << "There are no books yet" << endl;
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
        cout << "There are no books yet" << endl;
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
                break;
            }
        }
    }
    if (!found){
        cout << "No book found with this title or ID." << endl;
    }
}

void removeBook(vector<Book> &books){
    system("cls");
    if (books.empty()){
        cout << "There are no books yet" << endl;
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
        cout << "There are no users registered yet" << endl;
        return;
    }
    for (int i = 0; i < users.size(); i++){
        cout << "ID: " << users[i].getId() << "|" << "Username: " << users[i].getUsername() << endl;
    }
}

void lendBook(vector<Book> &books, vector<User> &users){
    system("cls");
    showUsers(users);
    if (users.empty()){
        cout << "Please register a user first" << endl;
        return;
    }
    cout << "Which user is borrowing the book? (write the ID):" << endl;
    int borrower_id;
    bool found = false;
    string borrower;
    cin >> borrower_id;
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
    cout << "Which user is borrowing the book? (write the ID):" << endl;
    int returner_id;
    bool found1 = false;
    string returner;
    cin >> returner_id;
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
    showBooks(books, "unavailable", returner);//quiero mostrar los libros que tiene el usuario en estado de unavailable
    cout << "0. I don't want to return anything" << endl;
    cout << "Which book do you want to return? (write the ID): " << endl;
    int ret;
    cin >> ret;
    if (ret == 0){
            return;
    }
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
            if (books[i].getStatus() == "available"){
                cout << "This book is already avialble" << endl;
                return;
            }
            else{
                books[i].setStatus("available");
                books[i].setUser(returner);
                cout << "Book returned!" << endl;
                return;
            }
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



void showUnavailable(vector<Book> &books){
    showBooks(books, "unavailable");
}

void showavailable(vector<Book> &books){
    showBooks(books, "available");
}

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
            case 10:
                showUnavailable(books);
                break;
            case 11:
                showavailable(books);
                break;
            default:
                cout << "This is not a valid option " << endl;
                break;
        }

    }
    return 0;
}
//POR HACER:
//el returnBook() tiene que mostrar solo los libros que el usuario tiene 