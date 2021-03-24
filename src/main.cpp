// Driver Code
#include "generator.h"
#include "parser.h"
#include "economic_dispatch.h"

#include <cmath>
#include <iostream>
#include <random>


int main() {
    // Parse load MW data
    Parser<double> loadParser = Parser<double>("load_mw_no_time.csv");
    std::vector<double> predictedLoad= loadParser.loadData();

    // Set up the RNG for picking random generators
    const int size = 5;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 4);
    std::vector<GeneratorType> typeList {GeneratorType::CoalFiredSteam,
                                         GeneratorType::OilFiredSteam,
                                         GeneratorType::SmallSub,
                                         GeneratorType::LargeSub,
                                         GeneratorType::OtherSteam};

    // Create two identical vectors of generators, one with off generators and one with on generators
    std::vector<Generator> offList;
    std::vector<Generator> onList;
    offList.reserve(size);
    onList.reserve(size);
    for(int i = 0; i < size; ++i) {
        GeneratorType type = typeList.at(dist(mt));
        offList.emplace_back(Generator(type, false));
        onList.emplace_back(Generator(type, true));
    }

    int rows = std::pow(2, size);

    int bitCombos[rows][size];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < size; j++) {
            int val = rows * j + i;
            int ret = (1 & (val >> j));
            bitCombos[i][j] = ret != 0;
        }
    }

    // Use the bitCombos to generate vectors of generator combinations
    std::vector<std::vector<Generator>> genCombos;
    for(int i = 0; i < rows; i++) {
        genCombos.emplace_back(std::vector<Generator>{});
        for(int j = 0; j < size; j++) {
            if(bitCombos[i][j] == 0) {
                genCombos.at(i).push_back(offList.at(j));
            } else {
                genCombos.at(i).push_back(onList.at(j));
            }
        }
    }
    //Pseudocode main function
    //Kirill Brainard

    //parse file into predictedLoad = [1000MW, 1200MW, 1650MW, etc]
    //make one of each generator
    //make combinations of each generator
    //calculate the cost for each combination at predictedLoad[0]
    // this includes lambda
    //[500$, 600$, 750$, 450$, 550$] @ predictedLoad[0]
    //make unitCommitMatrix = []
    //for load in predictedLoad:
    //calculate [500$, 600$, 750$, 450$, 550$]
    //append [500$, 600$, 750$, 450$, 550$] to unitCommitMatrix

    //{
    //[500$, 600$, 750$, 450$, 550$]
    //[500$, 600$, 750$, 450$, 550$]
    //[500$, 600$, 750$, 450$, 550$]
    //[500$, 600$, 750$, 450$, 550$]
    //}

    //calculate transitional

    //pass unitCommitMatrix into djikstras along with transitional costs
    //


    // Verify that genCombos contains sub-vectors containing each possible off/on combination
    for(const auto& combo : genCombos) {
        for(auto gen : combo) {
            std::cout << "gt: " << gen.getGeneratorType() << " on: " << gen.getIsOn() << '\t';
        }
        std::cout << std::endl;
    }
    
    
    // Narrow down to only on generators
    std::vector<std::vector<Generator>> onGenCombos;
    std::vector<Generator> onGens;
    for(const auto& combo : genCombos){
        for(auto gen : combo){
            if(gen.getIsOn()){
                onGens.push_back(gen);
            }
        }
        if(onGens.size() > 0){
            onGenCombos.push_back(onGens);
        }
        onGens.clear();
    }
    
    
    // Get Node Costs
    std::cout << "Load @ 1500" << std::endl;
    for(const auto& combo : onGenCombos){
        //for(auto load : predictedLoad){
            //Economic_Dispatch().lambdaFunction(load,combo,combo.size());
        //}
        std::cout << "On Generators: ";
        for(auto gen : combo){
            std::cout << gen.getGeneratorType() << ",";
        }
        std::cout << std::endl;
        std::cout << " Lambda Cost: " << Economic_Dispatch().divide(1500,combo) << std::endl;
    }
    
    return 0;
}
