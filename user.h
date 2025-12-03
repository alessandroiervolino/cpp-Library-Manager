#pragma once

#include <string>

using namespace std;

class User {
    private:
        string username;
        int userId;
        static int nextId;
    public:
        User(string _username);
        void setUsername(string username);
        string getUsername() const;
        int getId() const;
};

