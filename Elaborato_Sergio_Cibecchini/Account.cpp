//
// Created by sergio on 01/09/21.
//

#include "Account.h"


void Account ::deposit(int depositValue) {
    //saves previous file balance
    int previousBalance = getBalance();


    //deletes previous file contents
    std:: ofstream balanceOut;
    clearFile("balance.txt");

    //apre il file e cambia il valore
    balanceOut.open("balance.txt");
    int total = previousBalance + depositValue;
    balanceOut << std:: to_string(total);
    updateHistory(1,depositValue);
}


int Account ::getBalance() { //returns the balance
    std:: ifstream balanceIn ("balance.txt");
    std::  string out;
    getline(balanceIn, out);
    int convInt = std:: stoi(out);
    return convInt;
}

void Account ::updateHistory( int mode, int value) {
    std:: ofstream history ("history.txt", std:: ios_base :: app); //opens the file in append mode
    //changes the update basing on the mode
    if (mode == 1 && value > 0){
        history << (ownerFullName + " deposited " + std::to_string(value) + "$ ") << std:: endl ;
    }
    else if (mode == 2 && value > 0){
        history << (ownerFullName + " withdrawn " + std::to_string(value) + "$ ") << std:: endl;
    }
    else if (mode == 3){
        history << ownerFullName+ " created an account" << std:: endl;
    }
}

void Account ::setBalance(int value) { //sets balance
    //deletes previous file contents
    std:: ofstream balanceOut;
    clearFile("balance.txt");

    //apre il file e cambia il valore
    balanceOut.open("balance.txt");
    balanceOut << std::to_string(value);
}

bool Account::withdraw(int withdrawValue) {
//saves previous file balance
    int previousBalance = getBalance();
    if (withdrawValue <= previousBalance){
        //deletes previous file contents
        std:: ofstream balanceOut;
        clearFile("balance.txt");

        //apre il file e cambia il valore
        balanceOut.open("balance.txt");
        int total = previousBalance - withdrawValue;
        balanceOut << std:: to_string(total);
        updateHistory(2, withdrawValue);
        return true;
    }
    else {
        std::cout << "Error, exceeding account balance (" <<  std:: to_string(getBalance()) << "$)"<< std:: endl;
        return false;
    }


}

const std::string &Account::getOwnerFullName() const {
    return ownerFullName;
}

void Account::clearFile(const std::string &fileName) {
    std:: ofstream toClear;
    toClear.open(fileName, std:: fstream::out | std:: fstream::trunc);
    toClear.close();
}

void Account::setOwnerFullName(const std::string &ownerFullName) {
    Account::ownerFullName = ownerFullName;
}



