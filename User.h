//
// Created by Erik Gabrielsen on 11/7/22.
//
using namespace std;
#include <iostream>
#include <string>
#ifndef PROGRAM5_TEMPLATE_USER_H
#define PROGRAM5_TEMPLATE_USER_H

class User {
public:
    User();
    User(int, string, string, int);
    User& operator=(const User& copy);
    ~User();
    int getID() const;
    string getName() const;
    string getAddress() const;
    int getPeer() const ;
    void display_info();
private:
    int *id;
    std::string *name;
    std::string *address;
    int *homePeerId;

};


#endif //PROGRAM5_TEMPLATE_USER_H
