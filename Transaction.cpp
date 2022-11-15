#include "Transaction.h"
using namespace std;

Transaction::Transaction(){
    amount = nullptr;
    userFromId = nullptr;
    userToId = nullptr;

}
Transaction::Transaction(double newAmount, int newuserFromId, int newuserToId){
    amount = new double(newAmount);
    userFromId = new int(newuserFromId);
    userToId = new int(newuserToId);
}
Transaction& Transaction::operator=(const Transaction& copy){
    if(this == &copy){
        return *this;
    }
    amount = new double(copy.getAmount());
    userFromId = new int(copy.getuserFromId());
    userToId = new int(copy.getuserToId());
    return *this;
}
Transaction::~Transaction(){
    delete amount;
    delete userFromId;
    delete userToId;
}
double Transaction::getAmount() const{
    return *amount;
}
int Transaction::getuserFromId() const{
    return *userFromId;
}
int Transaction::getuserToId()const{
    return *userToId;
}