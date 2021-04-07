// Authors: Andres Sewell, Nate Shubert
// Driver Code
#include "generator.h"
#include "parser.h"
#include "economic_dispatch.h"
#include <cmath>
#include <iostream>
#include <random>

int main() {
    // Parse and load MW data
    Parser<double> loadParser = Parser<double>("load_mw_no_time.csv");
    std::vector<double> predictedLoad= loadParser.loadData();

    // Set up the PRNG for picking random generators. Setting a seed of 0 ensures one of each generator type.
    const long unsigned int seed = 0;
    std::default_random_engine engine{seed};
    std::uniform_int_distribution<int> dist(0, 100);
    std::vector<GeneratorType> typeList {GeneratorType::CoalFiredSteam,
                                         GeneratorType::OilFiredSteam,
                                         GeneratorType::SmallSub,
                                         GeneratorType::LargeSub,
                                         GeneratorType::OtherSteam};

    // Setting size too low will result in combos that can't satisfy the max load MW, and thus an empty genCombos
    // vector. Setting size larger than 16 will cause a segfault, presumably because the built in array can't handle
    // > 2^16 rows * size columns (1,048,576 elements) without heap allocation.
    const int size = 6;
    int rows = std::pow(2, size);

    // Create two identical vectors of generators, one with off generators and one with on generators
    std::vector<Generator> offList;
    std::vector<Generator> onList;
    offList.reserve(size);
    onList.reserve(size);
    for(int i = 0; i < size; ++i) {
        GeneratorType type = typeList.at(dist(engine) % 5);
        offList.emplace_back(Generator(type, false));
        onList.emplace_back(Generator(type, true));
    }

    // Generate an array containing every "size"-bit bitstring
    int bitCombos[rows][size];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < size; j++) {
            int val = rows * j + i;
            int ret = (1 & (val >> j));
            bitCombos[i][j] = ret != 0;
        }
    }

    // Use the bitstrings to generate vectors of generator combinations
    double highMW = *std::max_element(predictedLoad.begin(), predictedLoad.end());
    int highSumMW = 0;
    std::vector<std::vector<Generator>> genCombos;
    for(int i = 0; i < rows; i++) {
        highSumMW = 0;
        std::vector<Generator> temp;
        temp.reserve(size);
        for(int j = 0; j < size; j++) {
            if(bitCombos[i][j] == 0) {
                temp.push_back(offList.at(j));
            } else {
                highSumMW += onList.at(j).getMaxPowerOut();
                temp.push_back(onList.at(j));
            }
        }
        if(highMW < highSumMW) {
            genCombos.push_back(temp);
        }
    }

    // This generates what we need to pass to the pathfinding algorithm.
    Economic_Dispatch dispatch;
    std::vector<std::vector<double>> lambdas;
    for(auto &genCombo : genCombos) {
        std::vector<double> temp;
        temp.reserve(predictedLoad.size());
        for(auto load : predictedLoad) {
            temp.push_back(dispatch.lambdaFunction(load, genCombo, 0));
        }
        lambdas.emplace_back(temp);
    }

    // Print out the result of running the lambda function for each combo list. Looks like generator isOn status is not
    // taken into account when calculating economic dispatch? This results in every row in lambdas being identical,
    // which is not what we want.
    int count = 1;
    for(const auto& lambda : lambdas) {
        std::cout << "Combo-" << count << '\t';
        for(auto cost : lambda) {
            std::cout << cost << '\t';
        }
        std::cout << std::endl;
        ++count;
    }
    
    return 0;
}