//
// Created by sergio on 01/09/21.
//

#ifndef ELABORATO_SERGIO_CIBECCHINI_ACCOUNT_H
#define ELABORATO_SERGIO_CIBECCHINI_ACCOUNT_H
#include <iostream>
#include <fstream>
#include <utility>


class Account {
public:
    explicit Account (std :: string name) : ownerFullName(std::move(name)){}
    static int getBalance (); //returns the balance from the file as an int
    static void setBalance (int value);
    void updateHistory(int mode, int value = 0); //changes the history of the file
    void deposit (int depositValue);
    bool withdraw (int withdrawValue);
    static void clearFile(const std::string &fileName);



    const std::string &getOwnerFullName() const;

    void setOwnerFullName(const std::string &ownerFullName);


private:
    std:: string ownerFullName;
};


#endif //ELABORATO_SERGIO_CIBECCHINI_ACCOUNT_H
