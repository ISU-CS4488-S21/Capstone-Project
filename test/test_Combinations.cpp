// Author Deepson Khadka
//UnitTests for Combinations class functions

#include <gtest/gtest.h>
#include "../src/combination.h"
std::vector<Generator>fixtureOffList;
ComboPair fixtureComboPair(fixtureOffList, 200);

///Test fails if you have not included any error handling exception statement
TEST(CombinationTest,  infeasibilityTest){
    EXPECT_ANY_THROW("Infeasible combination");
}

///Tests passes if two values are equal
TEST(CombinationTest,  getEconomicDispatch){
    EXPECT_EQ(fixtureComboPair.getEconomicDispatch(), 200);
}