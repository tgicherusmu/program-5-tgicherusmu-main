//
// Created by Erik Gabrielsen on 11/7/22.
//

#ifndef PROGRAM5_TEMPLATE_PEER_H
#define PROGRAM5_TEMPLATE_PEER_H
using namespace std;
#include <string>
#include <vector>
#include "Transaction.h"

class Peer {
public:
    Peer();
    Peer(int, string);
    Peer& operator=(const Peer& copy);
    ~Peer();
    int getID() const;
    string getName() const;
    void addTransaction(Transaction*);
    void display_info();
    //void display_peer(int);
    void display_peer_total(int x);

private:
    int *id;
    std::string *name;
    std::vector<Transaction *> transactions;
};


#endif //PROGRAM5_TEMPLATE_PEER_H

