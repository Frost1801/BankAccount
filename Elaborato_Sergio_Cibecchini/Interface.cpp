//
// Created by sergio on 01/09/21.
//

#include "Interface.h"


bool Interface::startInterface() { //user interface to access all the account's operations
    int input = 0;
    if (!account){ //checks if the account is already activated or not
        std:: cout << "Welcome, to make transactions you need to create an account"<< std:: endl;
        std:: cout << "Press (1) to create an account" << std:: endl ;
        std:: cout << "Press (0) to exit" << std:: endl;
        while (!(getIntInput(input, 2))); //takes an int to evaluate the choice

        if (input == 0){
            std:: cout << "Quitting..." << std:: endl;
            return false;
        }

        else if (input == 1)
            createAccount(); //calls function to create account
    }
        printTextOptions();
        while (!(getIntInput(input, 6))); //gets input
        switch (input){
            case 1 : { //deposit option
                std:: cout << "Choose the amount you want to deposit, press (0) to cancel operation" << std:: endl;
                while (!(getIntInput(input)));
                if (input > 0){
                    account -> deposit(input);
                    std:: cout << "Deposited " << input << "$" << std:: endl;
                }
                break;
            }
            case 2:{ //withdraw option

                if (Account :: getBalance() > 0) {
                    std:: cout << "Choose the amount you want to withdraw, press (0) to cancel operation" << std:: endl;
                    do{
                        while (!(getIntInput(input)));
                    }while (!(account->withdraw(input)));
                    if (input > 0)
                        std:: cout << "Withdrawn " << input << "$" << std:: endl;
                }
                else {
                    std:: cout << "You haven't deposited any money yet!" << std:: endl;
                }

                break;
            }
            case 3: { //print balance option
                printBalance();
                break;
            }
            case 4: { //print all account history option
                printHistory();
                break;
            }
            case 5 : { //print all account details option
                std:: cout << account ->getOwnerFullName() << "'s account:" <<std:: endl;
                printBalance();
                printHistory();
                break;
            }
            case 0 : { // quits the program
                std:: cout << "Quitting..." << std:: endl;
                account ->clearFile("history.txt");
                account ->clearFile("balance.txt");
                return false;
            }
            default : {
                std:: cerr<< "Something went wrong (interface)" <<std:: endl;
                break;
            }
        }

    return true;
}

void Interface ::createAccount() {
    std:: cout << "Please insert a Username for your account: "<< std:: endl;
    std:: string inputName;
    while (!getStringInput(inputName, 5, 30)); //keeps asking for a username until a valid one is input

    account = std::make_unique<Account>(inputName);

    std:: cout << "Chosen Username: " << account->getOwnerFullName() << std:: endl;
    account ->setBalance(0);
    account ->clearFile("history.txt");
    account ->updateHistory(3);
    std:: cout << "Account was created successfully!" << std:: endl;
}

//FUNCTIONS TO GET INPUT

bool Interface ::getStringInput(std::string &input, int minLength, int maxLength) { //takes a string as input
    //performs various checks on that string, returns true if it passes, false otherwise
    try{
        std::getline(std:: cin,input);
        if (input.length() > maxLength){
            throw std:: out_of_range("String is bigger than maximum required length (" + std::to_string(maxLength) + ") chars");
        }
        if (input.length() < minLength){
            throw std:: out_of_range("String is smaller than minimum required length (" + std::to_string(minLength) + ") chars");
        }
    }
    catch (const std:: out_of_range & e){
        std:: cout << e.what()<< std:: endl;
        return false;
    }
    return true;
}

bool Interface ::getIntInput(int &input, int maxVal, int minVal) {//takes an int as input
    //performs various checks on the int, returns true if it passes, false otherwise
    try {
        std:: cin >> input;
        if (input < minVal)
            throw std:: out_of_range ("Input is smaller than minimum accepted value (" + std::to_string(minVal) +")");
        if (input > maxVal)
            throw std:: out_of_range ("Input exceeds the maximum number (" + std::to_string(maxVal) +")");
        if (input == 0)
            return true;
    }
    catch (const std:: out_of_range &e){
        std:: cout << e.what() << std:: endl;
        clear(); //clears the buffer
        return false;
    }
    clear(); //clears the buffer
    return true;
}

void Interface ::clear() {
    //std:: cin.get();
    //fflush(stdin);
    std:: cin.clear();
    //std:: cin.ignore(10000, '\n');
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//FUNCTIONS TO PRINT TO SCREEN

void Interface ::printHistory() { //prints the account transaction history
    std::ifstream history ("history.txt");
    std:: string textLine;
    std:: cout << "HISTORY:" << std:: endl;
    if (history.is_open())
        std::cout << history.rdbuf() << std:: endl;
}

void Interface::printBalance() const { //prints account balance
    std:: cout << "BALANCE: " << account ->getBalance() << "$" << std:: endl;
}

void Interface ::printTextOptions() { //prints the interface options
    std:: cout << "Welcome to your account"<< std:: endl;
    std:: cout << "Press (1) to deposit cash" << std:: endl;
    std:: cout << "Press (2) to withdraw cash" << std:: endl;
    std:: cout << "Press (3) to check your account balance" << std:: endl;
    std:: cout << "Press (4) to check your account transactions history " << std:: endl;
    std:: cout << "Press (5) to check your account full information" << std:: endl;
    std:: cout << "Press (0) to quit" << std:: endl;
}
