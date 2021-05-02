#include <gtest/gtest.h>
#include "../src/generator.h"

Generator fixtureGenerator;

TEST(GeneratorTest, sumTest){
    EXPECT_EQ(3, fixtureGenerator.sum(1, 2));
}

TEST(GeneratorTest, getFuelCostTest){
    EXPECT_EQ(fixtureGenerator.getFuelCost(),0);
}

TEST(GeneratorTest, getStartUpCostTest){

}

TEST(GeneratorTest, getShutDownCostTest){

}

TEST(GeneratorTest, getBurnRateTest){

}

TEST(GeneratorTest, getBTest){

}


TEST(GeneratorTest, getCTest){

}

TEST(GeneratorTest, getMaxPowerOut){

}

TEST(GeneratorTest, getMinPowerOutTest){

}

TEST(GeneratorTest, getIsOnTest){

}

TEST(GeneratorTest, turnOnTest){

}

TEST(GeneratorTest, turnOffTest){

}

TEST(GeneratorTest, getGeneratorTypeTest){

}

TEST(GeneratorTest, randNumTest){

}
