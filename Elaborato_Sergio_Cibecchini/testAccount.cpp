//
// Created by sergio on 01/09/21.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Account.h"

using testing :: Eq;

namespace {
    class AccountTester : public testing :: Test { //test fixture for account methods
    public:
        std:: unique_ptr<Account> testedAccount;
        AccountTester () {
            testedAccount = std::make_unique<Account>("Test");
        }
        void SetUp () override{
            testedAccount->setBalance(0);
        }
        void TearDown () override{
            testedAccount ->clearFile("history.txt");
            testedAccount ->clearFile("balance.txt");
        }
    };
}

TEST_F (AccountTester, gettingBalance){ //checks if SetUp worked and if getBalance returns the right value
    int setValue = testedAccount -> getBalance();
    ASSERT_EQ(0, setValue);
}

TEST_F (AccountTester, depositTest){ //checks deposit function
    testedAccount->deposit(100);
    ASSERT_EQ(100, testedAccount -> getBalance ());
}

TEST_F (AccountTester, withdrawValidTest){ //checks basic withdraw function action
    testedAccount->deposit(100);
    testedAccount->withdraw(100);
    ASSERT_EQ(0, testedAccount -> getBalance());
}
TEST_F (AccountTester, withdrawInvalidTest){ //checks if the withdrawal is activated even with insufficient balance
    testedAccount ->deposit(100);
    testedAccount->withdraw(101);
    ASSERT_EQ(100, testedAccount -> getBalance());
}

TEST_F (AccountTester, withdrawReturnTrue){ //checks return value in the case of a successful withdrawal
    testedAccount ->deposit(100);
    ASSERT_EQ(true, testedAccount -> withdraw (100));
}
TEST_F (AccountTester, withdrawReturnFalse){ //checks return value in the case of a failed withdrawal
    testedAccount ->deposit(100);
    ASSERT_EQ(false, testedAccount -> withdraw (101));
}

TEST_F (AccountTester, checkHistory){ //checks if history is updated correctly
    testedAccount ->clearFile("history.txt");
    testedAccount ->deposit(100);
    std::ifstream history ("history.txt");
    std:: string textLine;
    std::getline(history,textLine);
    ASSERT_EQ(textLine, "Test deposited 100$ ");
}
