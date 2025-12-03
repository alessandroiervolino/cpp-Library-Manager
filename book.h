#pragma once

#include <string>

using namespace std;

class Book {
    private:
        string tittle, author, status, user;
        int id;
        static int nextId;

    public:
        Book(string _tittle, string _author);
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

