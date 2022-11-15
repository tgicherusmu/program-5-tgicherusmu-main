//
// Created by Erik Gabrielsen on 11/7/22.
//

#ifndef PROGRAM5_TEMPLATE_DLTNETWORK_H
#define PROGRAM5_TEMPLATE_DLTNETWORK_H

#include <vector>
#include <iostream>
#include "User.h"
#include "Peer.h"

class DLTNetwork {
public:
    DLTNetwork();
    void start();
    void create_user(int, string, string, int);
    void create_peer(int, string);
    void create_transaction(double, int, int);

private:
    std::vector<User *> users;
    std::vector<Peer *> peers;
};


#endif //PROGRAM5_TEMPLATE_DLTNETWORK_H
