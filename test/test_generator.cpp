/// Author- Deepson Khadka
///Testing Generator class using Google Test

#include <gtest/gtest.h>
#include "../src/Generator.h"

Generator fixtureGenerator;

///Testing Sum Function
TEST(test_Generator, test_Sum){

    EXPECT_EQ(6, fixtureGenerator.sum(2, 4));
}

///Testing fuel cost
TEST(test_Geneartor, test_FuelCost){
    EXPECT_EQ(fixtureGenerator.getFuelCost(), 0);
}

///Testing startup cost :
TEST(test_Generator, test_StartupCost){
    EXPECT_EQ(fixtureGenerator.getStartUpCost(), 0);
}

///Testing shutdown cost :
TEST(test_Generator, test_ShutdownCost){
    EXPECT_EQ(fixtureGenerator.getShutDownCost(), 0);
}

///Testing getBurnRate
TEST(test_Generator, test_BurnRate){
    EXPECT_EQ(fixtureGenerator.getBurnRate(), 0);
}

///Testing getB
TEST(test_Generator, test_getB){
    EXPECT_EQ(fixtureGenerator.getB(), 0);
}

///Testing getC
TEST(test_Generator, test_getC){
    EXPECT_EQ(fixtureGenerator.getC(), 0);
}

///Testing getMaxPowerOut
TEST(test_Generator, test_MaxPowerOut){
    EXPECT_EQ(fixtureGenerator.getMaxPowerOut(), 0);
}

///Testing getMinPowerOut
TEST(test_Generator, test_MinPowerOut){
    EXPECT_EQ(fixtureGenerator.getMinPowerOut(), 0);
}

///Testing getIsOn
TEST(test_Generator,test_getIsOn){
    EXPECT_EQ(fixtureGenerator.getIsOn(), false);
}

