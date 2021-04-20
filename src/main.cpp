// Authors: Andres Sewell, Nate Shubert, Marcus Goeckner
// Driver Code
#include "combination.h"
#include "DP.h"
#include "generator.h"
#include "parser.h"
#include "economic_dispatch.h"
#include <cmath>
#include <iostream>
#include <random>
#include <bitset>

int main() {
    // Parse and load MW data
    Parser<double> loadParser = Parser<double>("load_mw_no_time.csv");
    std::vector<double> predictedLoad = loadParser.loadData();

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
    const int rows = static_cast<int>(std::pow(2, size));

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
    std::vector<std::vector<int>> bitCombos;
    bitCombos.reserve(rows);
    for(int i = 0; i < rows; i++) {
        std::vector<int> temp;
        temp.reserve(size);
        for(int j = 0; j < size; j++) {
            int val = rows * j + i;
            int ret = (1 & (val >> j));
            temp.push_back(ret != 0);
        }
        bitCombos.push_back(temp);
    }

    // Use the bitstrings to generate a vector of ComboPairs.
    Economic_Dispatch dispatch;
    std::vector<ComboPair> combinations;
    double minMW = *std::min_element(predictedLoad.begin(), predictedLoad.end());
    for(int i = 0; i < rows; i++) {
        std::vector<Generator> combo;
        combo.reserve(size);
        int minSumMW = 0;
        for(int j = 0; j < size; j++) {
            if(bitCombos.at(i).at(j) == 0) {
                combo.push_back(offList.at(j));
            } else {
                minSumMW += onList.at(j).getMaxPowerOut();
                combo.push_back(onList.at(j));
            }
        }
        if(minSumMW > minMW) {
            combinations.emplace_back(combo, dispatch.divide(predictedLoad.at(0), combo));
        }
    }

    std::vector<std::vector<Generator>> next;
    next.reserve(combinations.size());
    for(ComboPair pair : combinations) {
        std::vector<Generator> temp = pair.getCombo();
        next.push_back(temp);
    }

    // Validate that the new std::vector<ComboPair> structure contains the contents that we expect it to.
    int count = 1;
    for(ComboPair pair : combinations) {
        std::cout << "Combo #" << count << ":\t";
        for(Generator generator : pair.getCombo()) {
            std::cout << generator.getIsOn() << " ";
        }
        std::cout << "\nEconomic Dispatch:\t" << pair.getEconomicDispatch() << std::endl;
        std::cout << std::endl;
        ++count;
    }

    std::cout << "\nNow adding the \"cheapest\" source and its edge to each combinations running cost for the next time step...\n\n\n";

    DynamicProgrammingAlgo dp;
    std::vector<std::pair <std::vector<Generator>,double>> sources = dp.cheapestRoutes(combinations, next);
    // adds some arbitrary S+E cost (5000) to all of the source combinations from the initial state
    // this arbitrary S+E cost should be the cheapest one from the previous time step
    std::vector<std::pair <std::vector<Generator>,double>> newStates = dp.addCheapestSE(sources, 5000);

    // show that cheapest routes and addCheapestSE function work together
    count = 1;
    for(std::pair<std::vector<Generator>,double> pair : newStates) {
        std::cout << "Combo #" << count << ":\t";
        for(Generator generator : pair.first) {
            std::cout << generator.getIsOn() << " ";
        }
        std::cout << "\nNew total Economic Dispatch (added 5000):\t" << pair.second << std::endl;
        std::cout << std::endl;
        ++count;
    }

    return 0;
}
