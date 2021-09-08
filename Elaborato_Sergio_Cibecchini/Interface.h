//
// Created by sergio on 01/09/21.
//

#ifndef ELABORATO_SERGIO_CIBECCHINI_INTERFACE_H
#define ELABORATO_SERGIO_CIBECCHINI_INTERFACE_H
#include <iostream>
#include <exception>
#include <string>
#include <limits>
#include <fstream>
#include <memory>
#include "Account.h"

class Interface {
public:

    bool startInterface ();
    static void printTextOptions(); //prints to the screen the various action options the user has
    static void printHistory (); //prints the file containing the transaction history
    void createAccount ();
    void printBalance () const;



    //input methods
    static bool getStringInput (std:: string & input, int minLength = 0, int maxLength = 100);
    static bool getIntInput (int &input, int maxVal = 100000000, int minVal = 0);
    static void clear ();

private:
    std:: unique_ptr<Account> account;
};


#endif //ELABORATO_SERGIO_CIBECCHINI_INTERFACE_H
