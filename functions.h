#pragma once
#include <vector>
#include "book.h"
#include "user.h"

void addBook(vector<Book> &books);
void showBooks(const vector<Book> &books, string filter = "all", string user = "all");
void findBook(const vector<Book> &books);
void removeBook(vector<Book> &books);
void showUsers(const vector<User> &users);
void lendBook(vector<Book> &books, vector<User> &users);
void returnBook(vector<Book> &books, const vector<User> users);
void registerUser(vector<User> &users);