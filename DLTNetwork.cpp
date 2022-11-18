//
// Created by Erik Gabrielsen on 11/7/22.
//

#include "DLTNetwork.h"
#include <fstream>
#include <ostream>
#include <sstream>
#include <iostream>
using namespace std;

DLTNetwork::DLTNetwork() {

}

void DLTNetwork::start() {
    std::cout << "Starting your DLT Network..." << std::endl;
    ifstream input;
    input.open("../input.txt"); //open file
    string currLine;
    getline(input, currLine);
    while(!input.eof()) {
        cout<< currLine << endl;
        if(currLine.substr(0, 11)=="CREATE_PEER") {
            stringstream line(currLine);
            string id;
            string name;
            getline(line, id,' ');
            getline(line, id,'|');
            getline(line, name);
            create_peer(stoi(id), name);
        }
        else if(currLine.substr(0, 11)=="CREATE_USER"){
            stringstream line(currLine);
            string id;
            string name;
            string address;
            string peer;
            getline(line, id,' ');
            getline(line, id,'|');
            getline(line, name,'|');
            getline(line, address,'|');
            getline(line, peer);
            create_user(stoi(id), name, address, stoi(peer));
        }
        else if(currLine.substr(0, 18)=="CREATE_TRANSACTION"){
            stringstream line(currLine);
            string amount;
            string userFromId;
            string userToId;
            getline(line, amount,' ');
            getline(line, amount,'|');
            getline(line, userFromId,'|');
            getline(line, userToId);
            create_transaction(stod(amount), stoi(userFromId), stoi(userToId));
        }
        else if(currLine.substr(0, 11)=="DISPLAY_ALL"){
            for(int i = 0; i<users.size(); i++){
                users.at(i)->display_info();
            }
            for(int i = 0; i<peers.size(); i++){
                peers.at(i)->display_info();
            }
        }
        else if(currLine.substr(0, 18)=="DISPLAY_PEER_TOTAL"){
            stringstream line(currLine);
            string peerID;
            getline(line, peerID,' ');
            getline(line, peerID);
            int peerIDNum = stoi(peerID);
            for (int i = 0; i < peers.size(); i++) {
                if (peers.at(i)->getID() == peerIDNum) {
                    peers.at(i)->display_peer_total();
                }
            }
        }
        else if(currLine.substr(0, 12)=="DISPLAY_PEER"){
            stringstream line(currLine);
            string peerID;
            getline(line, peerID,' ');
            getline(line, peerID);
            int peerIDNum = stoi(peerID);
            for(int i = 0; i<peers.size(); i++){
                if(peers.at(i)->getID()==peerIDNum){
                    peers.at(i)->display_info();
                }
            }
        }
        else if(currLine.substr(0, 12)=="DISPLAY_USER"){
            stringstream line(currLine);
            string userID;
            getline(line, userID,' ');
            getline(line, userID);
            int userIDNum = stoi(userID);
            for(int i = 0; i<users.size(); i++){
                if(users.at(i)->getID()==userIDNum){
                    users.at(i)->display_info();
                }
            }
        }
        else{
            cout << "Invalid statement" << endl;
        }
       getline(input, currLine);
    }
}

void DLTNetwork::create_user(int id, string name, string address, int peer){
   User* newUser = new User(id, name, address, peer);
   users.push_back(newUser);
}

void DLTNetwork::create_peer(int id, string name){
    Peer* newPeer = new Peer(id, name);
    peers.push_back(newPeer);
}

void DLTNetwork::create_transaction(double amount, int userFromId, int userToId){
    Transaction* newTransaction = new Transaction(amount, userFromId,userToId);
    for(int i = 0; i < users.size(); i++){
        if(users.at(i)->getID()==userFromId){
            int peerNumber = users.at(i)->getPeer();
            for(int j = 0; j < peers.size(); j++){
                if(peers.at(j)->getID()==peerNumber){
                    peers.at(j)->addTransaction(newTransaction);
                }
            }
        }
    }

    //This command will create a new Transaction object, then add the transaction to both the Peer of the "from" user and to the Peer of the "to" User, therefore distributing its information to the 2 sources.
}
