#include <iostream>
#include <string>
#include <limits>
#include <vector>


using namespace std;

class Book {
    private:
        string tittle, author, status;
        int id;
        static int nextId;

    public:
        Book(string _tittle, string _author): tittle(_tittle), author(_author){id = nextId ++; status = "aviable";/*autoincrementacion del id */} //constructor
        void setTittle(string tittle);
        void setAuthor(string author);
        void setStatus(string status);   
        string getTittle() const;
        string getAuthor() const;
        int getId() const;
        string getStatus() const;
    
};

int Book::nextId = 1;

void Book::setTittle(string _tittle){
    tittle = _tittle;
}

void Book::setAuthor(string _author){
    author = _author;
}

void Book::setStatus(string _status){
    status = _status;
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

void addBook(vector<Book> &books){
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
}

void showBooks(const vector<Book> &books, string filter = "all"){
    if (books.empty()){
        cout << "There are no books yet" << endl;
        return;
    }
    for (int i=0; i < books.size(); i++){
        if (filter == "all" || books[i].getStatus() == filter){
        cout << "ID: " << books[i].getId() << "|" << "Tittle: " << books[i].getTittle() << "|" << "Author: " << books[i].getAuthor() << "|" << "Status: " << books[i].getStatus() << endl;
        }
    }
    
}

void findBook(const vector<Book> &books){
    if (books.empty()){
        cout << "There are no books yet" << endl;
        return;
    }
    string find;
    cout << "Write the tittle or the ID of the book you want to find: " << endl;
    if (cin.peek() == '\n'){
        cin.ignore();
    }
    getline(cin, find);
    for(int i = 0; i < books.size(); i++){
        if (find == books[i].getTittle()){
            cout << "Book found! by Tittle" << endl;
            cout << "Tittle: " << books[i].getTittle() << " Author: " << books[i].getAuthor() << " Status: " << books[i].getStatus() << endl;
            return;
        }
        else{
            try
            {
                int id = stoi(find);
                for(int i = 0; i < books.size(); i++){
                    if(id == books[i].getId()){
                        cout << "Book found! by ID" << endl;
                        cout << "Tittle: " << books[i].getTittle() << " Author: " << books[i].getAuthor() << " Status: " << books[i].getStatus() << endl;
                        return;
                    }
                }
            }
            catch(invalid_argument&)
            {
                cout << "No book found with this title or ID." << endl;
            }
        }
    }
}

void removeBook(vector<Book> &books){
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

void lendBook(vector<Book> &books){
    cout << "Which book do you want to lend? (write the ID): " << endl;
    showBooks(books, "aviable");//quiero mostrar solo los que estan en status == "aviable"
    int lend;
    cin >> lend;
    bool found = false;
    for (int i = 0; i < books.size(); i++){
        if (lend == books[i].getId() && books[i].getStatus() == "aviable"){
            books[i].setStatus("unaviable");
            cout << "Book lended!" << endl;
            return;            
        }
        else {
            cout << "This book is unaviable" << endl;
            return;
        }
        
    }
    if (!found){
        cout << "No book with that ID exists." << endl;
        return;
    } 
}

void returnBook(vector<Book> &books){
    cout << "Which book do you want to return? (write the ID): " << endl;
    showBooks(books, "unaviable");
    int ret;
    cin >> ret;
    bool found = false;
    for (int i = 0; i < books.size(); i++){
        if (books[i].getId() == ret){
            found = true;
            if (books[i].getStatus() == "aviable"){
                cout << "This book is already avialble" << endl;
                return;
            }
            else{
                books[i].setStatus("aviable");
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

int main(){
    vector<Book> books;
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
                break;
            case 2:
                showBooks(books);
                break;
            case 3:
                findBook(books);
                break;
            case 4:
                removeBook(books);
                break;
            case 5:
                lendBook(books);
                break;
            case 6:
                returnBook(books);
                break;
            case 7:
                //registerUser();
                break;
            case 8:
                //showUsers();
                break;
            case 9:
                cout << "Exiting..." << endl;
                return 0;
                break;
            default:
                cout << "wrong number " << endl;
                break;
        }

    }
    return 0;
    
}
//POR HACER:
//falta poner la opcion 0 en algunas funciones
//seguir con las ultimas funciones por crear
//evitar crash si el usuario no pone numeros en las funciones