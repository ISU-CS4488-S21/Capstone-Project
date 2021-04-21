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
    Parser<unsigned int> loadParser = Parser<unsigned int>("load_mw_no_time.csv");
    std::vector<unsigned int> predictedLoad = loadParser.loadData();

    // Set up the PRNG for picking random generators. Setting a seed of 0 ensures one of each generator type.
    const long unsigned int seed = 0;
    std::default_random_engine engine{seed};
    std::uniform_int_distribution<int> dist(0, 100);
    std::vector<GeneratorType> typeList {GeneratorType::CoalFiredSteam,
                                         GeneratorType::OilFiredSteam,
                                         GeneratorType::SmallSub,
                                         GeneratorType::LargeSub,
                                         GeneratorType::OtherSteam};

    // Number of generators we want to use
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
    unsigned int minMW = *std::min_element(predictedLoad.begin(), predictedLoad.end());
    int cheapestIndex = 0;
    unsigned int cheapestCost = std::numeric_limits<unsigned int>::max();
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
            unsigned int currentCost = dispatch.divide(predictedLoad.at(0), combo);
            combinations.emplace_back(combo, currentCost);
            if(currentCost < cheapestCost) {
                cheapestCost = currentCost;
                cheapestIndex = i;
            }
        }
    }

    std::vector<ComboPair> next;
    next.reserve(combinations.size());
    for(ComboPair pair : combinations) {
        next.push_back(pair);
    }

    DynamicProgrammingAlgo dp;
    std::vector<std::pair<ComboPair, unsigned int>> sources;
    std::vector<std::pair<ComboPair, unsigned int>> newStates;
    sources = dp.cheapestRoutes(combinations, next);
    for(int i = 1; i < predictedLoad.size(); i++) {

        newStates = dp.addCheapestSE(sources, cheapestCost);

        sources = newStates;
        for(auto pair : combinations) {
            unsigned int currentCost = dispatch.divide(predictedLoad.at(i), pair.getCombo());
            pair.setEconomicDispatch(currentCost);
            // Do something here to get next cheapest cost?
        }
    }

    // adds some arbitrary S+E cost (5000) to all of the source combinations from the initial state
    // this arbitrary S+E cost should be the cheapest one from the previous time step
    /*
    int count = 1;
    std::cout << "Time Step " << i + 1 << "\n\n";
    for(ComboPair pair : combinations) {
        std::cout << "Combo #" << count << ":\t";
        for(Generator generator : pair.getCombo()) {
            std::cout << generator.getIsOn() << " ";
        }
        std::cout << "\nEconomic Dispatch:\t" << newStates.at(count - 1).second << std::endl;
        std::cout << std::endl;
        ++count;
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

    std::cout << "\nNow adding the \"cheapest\" source and its edge to each combinations running cost for each time step...\n\n\n";
    */

    return 0;
}
