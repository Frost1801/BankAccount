//Classi che rappresentano transazioni finanziarie su un conto corrente (ingresso e uscita).
// Le classi devono essere in grado leggere e salvare i dati su file.

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Interface.h"

int main() {
/*

    testing :: InitGoogleTest();
    return RUN_ALL_TESTS();
*/


    Interface test;
    while (test.startInterface());
    return 0;


}
