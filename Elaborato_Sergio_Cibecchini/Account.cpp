//
// Created by sergio on 01/09/21.
//

#include "Account.h"


void Account ::deposit(int depositValue) { //deposit function
    //saves previous file balance
    int previousBalance = getBalance();


    //deletes previous file contents
    std:: ofstream balanceOut;
    clearFile("balance.txt");

    //opens file and changes value stored inside
    balanceOut.open("balance.txt");
    int total = previousBalance + depositValue;
    balanceOut << std:: to_string(total);
    //updates history file with the changes
    updateHistory(1,depositValue);
}

bool Account::withdraw(int withdrawValue) {
//saves previous file balance
    int previousBalance = getBalance();
    if (withdrawValue <= previousBalance){ //checks if we have enough funds to withdraw
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

void Account ::updateHistory( int mode, int value) { //updates transaction history file

    std:: ofstream history ("history.txt", std:: ios_base :: app); //opens the file in append mode
    //changes the update basing on the selected mode
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

int Account ::getBalance() { //returns the balance
    std:: ifstream balanceIn ("balance.txt");
    std::  string out;
    //grabs first string of the balance file
    getline(balanceIn, out);
    //converts string to int
    int convInt = std:: stoi(out);
    return convInt;
}

const std::string &Account::getOwnerFullName() const { //getter
    return ownerFullName;
}

void Account::clearFile(const std::string &fileName) { //clears the contents of a file named fileName
    std:: ofstream toClear;
    toClear.open(fileName, std:: fstream::out | std:: fstream::trunc); //trunc deletes any contents that existed in the file before it is open
    toClear.close();
}

void Account::setOwnerFullName(const std::string &ownerFullName) {
    Account::ownerFullName = ownerFullName;
}



