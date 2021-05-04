#include <gtest/gtest.h>
#include "../src/generator.h"

///Test passes if fuelCost is greater than 0
TEST(GeneratorTest, getFuelCostTest){
    enum GeneratorType {
        CoalFiredSteam,
        OilFiredSteam,
        SmallSub,
        LargeSub,
        OtherSteam,
    };
    Generator fixtureGenerator;

    EXPECT_FALSE(fixtureGenerator.getFuelCost()<0);
}

///Test fails if startup cost is less than 0
TEST(GeneratorTest, getStartUpCostTest){
    enum GeneratorType {
        CoalFiredSteam,
        OilFiredSteam,
        SmallSub,
        LargeSub,
        OtherSteam,
    };
    Generator fixtureGenerator;
    EXPECT_FALSE(fixtureGenerator.getStartUpCost()<0);
}

///Test fails if shutdown cost is less than 0
TEST(GeneratorTest, getShutDownCostTest){
    enum GeneratorType {
        CoalFiredSteam,
        OilFiredSteam,
        SmallSub,
        LargeSub,
        OtherSteam,
    };
    Generator fixtureGenerator;
EXPECT_FALSE(fixtureGenerator.getShutDownCost()<0);
EXPECT_TRUE(fixtureGenerator.getShutDownCost()>0);
}

///Test passes if generatorType is enum 1 or CoalFiredSteam
TEST(GeneratorTest, getGeneratorTypeTest){
    enum GeneratorType {
        CoalFiredSteam,
        OilFiredSteam,
        SmallSub,
        LargeSub,
        OtherSteam,
    };
    Generator fixtureGenerator;
    EXPECT_EQ(fixtureGenerator.getGeneratorType(),CoalFiredSteam);
}

///Test passes if power is >0
TEST(GeneratorTest, powerBaseOutTest){
    enum GeneratorType {
        CoalFiredSteam,
        OilFiredSteam,
        SmallSub,
        LargeSub,
        OtherSteam,
    };
    Generator fixtureGenerator;

    EXPECT_TRUE(fixtureGenerator.getMaxPowerOut()>0);
    EXPECT_TRUE(fixtureGenerator.getMinPowerOut()>0);
}

///Test passes iff maxPower>minPower && >0
TEST(GeneratorTest,powerOutTest){
    enum GeneratorType {
        CoalFiredSteam,
        OilFiredSteam,
        SmallSub,
        LargeSub,
        OtherSteam,
    };
    Generator fixtureGenerator;
    double minPower=fixtureGenerator.getMinPowerOut();
    double maxPower=fixtureGenerator.getMaxPowerOut();
   EXPECT_TRUE(maxPower>0 && maxPower>minPower );
}

///Test passes if it returns true
TEST(GeneratorTest, getIsOnTest){
    enum GeneratorType {
        CoalFiredSteam,
        OilFiredSteam,
        SmallSub,
        LargeSub,
        OtherSteam,
    };
    Generator fixtureGenerator;
    EXPECT_EQ(fixtureGenerator.getIsOn(),true);
}



