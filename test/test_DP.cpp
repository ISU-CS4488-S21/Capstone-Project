//Author Deepson Khadka
//Tests DP class units
//Couldn't test this file due Error in setting up testing

#include <gtest/gtest.h>
#include "../src/DP.h"
#include "../src/parser.h"

DynamicProgrammingAlgo fixtureDP;

///supposed to test economicDispatch
TEST(DPTest,  economicDispatchTest){
    std::cout << std::endl << std::endl<<std::endl;
    std::cout << "Couldn't test this file due Error in setting up testing" << std::endl;
    std::cout << std::endl << std::endl<<std::endl;

    std::vector<std::pair<ComboPair, unsigned int>> combinations;
    Parser<unsigned int> loadParser = Parser<unsigned int>("../load_mw_no_time.csv");
    std::vector<unsigned int> predictedLoad = loadParser.loadData();

    std::pair<ComboPair, unsigned int> source_combo = fixtureDP.getCheapestViableSource(combinations, predictedLoad.at(0));
    EXPECT_EQ(source_combo.first.getEconomicDispatch(),0);

}

///supposed to test cheapest S+E cost
TEST(DPTest,  getEdgeCostTest){

}

///supposed to test cheapest node
TEST(DPTest,  cheapestForNodeTest){

}

///supposed to test cheapest S+E cost
TEST(DPTest,  addCheapestSETest){


}