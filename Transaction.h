//
// Created by Erik Gabrielsen on 11/7/22.
//

#ifndef PROGRAM5_TEMPLATE_TRANSACTION_H
#define PROGRAM5_TEMPLATE_TRANSACTION_H
using namespace std;

class Transaction {
public:
    Transaction();
    Transaction(double, int, int);
    Transaction& operator=(const Transaction& copy);
    ~Transaction();
    double getAmount() const;
    int getuserFromId() const;
    int getuserToId() const;
private:
    double *amount;
    int *userFromId;
    int *userToId;

};


#endif //PROGRAM5_TEMPLATE_TRANSACTION_H
