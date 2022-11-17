//
// Created by Erik Gabrielsen on 11/7/22.
//

#include "Peer.h"
#include <iostream>
#include <iomanip>
using namespace std;


Peer::Peer(){
    id = nullptr;
    name = nullptr;
}

Peer::Peer(int newID, string newName){
    id = new int(newID);
    name = new string(newName);
}
Peer& Peer::operator=(const Peer& copy){
    if(this == &copy){
        return *this;
    }
    id = new int(copy.getID());
    name = new string(copy.getName());
    return *this;
}
Peer::~Peer(){
    delete id;
    delete name;
    for(int i = 0; i > transactions.size(); i++){
        delete transactions.at(i);
    }
}
int Peer::getID() const{
    return *id;
}
string Peer::getName() const{
    return *name;
}

void Peer::addTransaction(Transaction* newTrans) {
    transactions.push_back(newTrans);
}

void Peer::display_info() {
    cout << "ID: " << *id << endl;
    cout << "Name: " << *name << endl;
}
void Peer::display_peer_total() {
    //for (int i = 0; i < transactions.size(); i++) {
    //  if (transactions.at(i)->getAmount() == peerIDNum) {
    //    for (int j = 0; j < peers.size(); j++) {
    //      transactions.at(j).display_info();
    //}

    //}
    int totalTransaction = 0;
    for (int i = 0; i < transactions.size(); i++) {
        totalTransaction += transactions.at(i)->getAmount();
        cout << fixed << setprecision(2) << "Peer Total: $" << totalTransaction << " USD" << endl;
    }


    //create integer for total transaction amount
    //loop thru transactions vector
    //for each transaction, add to total
    //display total
}




//display info in user and peer
//display all for loop for both
