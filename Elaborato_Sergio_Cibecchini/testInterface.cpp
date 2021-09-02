//
// Created by sergio on 01/09/21.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Interface.h"

using testing :: Eq;

namespace {
class InterfaceTester : public testing :: Test { //test fixture
public:
    std:: unique_ptr<Interface> testedInterface;
    InterfaceTester () {
        testedInterface = std::make_unique<Interface>();
    }

};
}
/*

TEST_F (InterfaceTester, intInput){ //checks basic int input using getIntInput
    int value;
    std:: cout << "Enter (1)" << std:: endl;
    testedInterface->getIntInput(value);
    ASSERT_EQ(1,value);
}

TEST_F (InterfaceTester, stringInput){ //checks basic string input using getStringInput
    std:: string inputString;
    std:: cout << "Enter (hello)" << std:: endl;
    testedInterface->getStringInput(inputString);
    ASSERT_EQ("hello",inputString);
}

*/
