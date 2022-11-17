//
// Created by Erik Gabrielsen on 11/7/22.
//

#include "User.h"
#include "string"
using namespace std;

User::User(){
    id = nullptr;
    name = nullptr;
    address = nullptr;
    homePeerId = nullptr;

}
User::User(int newID, string newName, string newAddress, int newHomePeerId){
    id = new int(newID);
    name = new string(newName);
    address = new string(newAddress);
    homePeerId = new int(newHomePeerId);
}
User& User::operator=(const User& copy){
    if(this == &copy){
        return *this;
    }
    id = new int(copy.getID());
    name = new string(copy.getName());
    address = new string(copy.getAddress());
    homePeerId = new int(copy.getPeer());
    return *this;
}
User::~User(){
    delete id;
    delete name;
    delete address;
    delete homePeerId;
}
int User::getID() const{
    return *id;
}
string User::getName() const{
    return *name;
}
string User::getAddress() const{
    return *address;
}
int User::getPeer() const{
    return *homePeerId;
}

void User::display_info() {
        cout << "ID: " << *id << endl;
        cout << "Name: " << *name << endl;
        cout << "Address: " << *address << endl;
        cout << "Home Peer ID: " << *homePeerId << endl;
}
