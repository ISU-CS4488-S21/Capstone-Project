// Author Deepson Khadka
//UnitTests economic dispatch class's functions

#include <gtest/gtest.h>
#include "../src/economic_dispatch.h"

Economic_Dispatch fixture;

///Tests SkippedCounter value equal to initialized
TEST(EcoDispatchTest,  getSkipCounterTest){
EXPECT_EQ(0, fixture.getSkipCounter());
}

///Tests TestedCounter value
TEST(EcoDispatchTest, getTestedCounterTest){
    EXPECT_EQ(0, fixture.getTestedCounter());
}

