#include "book.h"

int Book::nextId = 1;

Book::Book(string _tittle, string _author): tittle(_tittle), author(_author){id = nextId ++; status = "available";}

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
