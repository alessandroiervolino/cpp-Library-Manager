#include "user.h"

int User::nextId = 1;

User::User(string _username): username(_username){userId = nextId ++;}

void User::setUsername(string _username){
    username = _username;
}

string User::getUsername() const{
    return username;
}

int User::getId() const{
    return userId;
}