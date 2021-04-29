// Authors: Andres Sewell, Nate Shubert, Marcus Goeckner
// Driver Code
#include "combination.h"
#include "DP.h"
#include "generator.h"
#include "parser.h"
#include "economic_dispatch.h"
#include "ThreadPool.h"
#include <chrono>
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
    const int size = 8;
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
    auto t0 = std::chrono::high_resolution_clock::now();
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
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << size << "-bit bitstrings generated in " << std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count() << " microseconds" << std::endl;

    // Use the bitstrings to generate a vector of ComboPairs.
    auto t2 = std::chrono::high_resolution_clock::now();
    std::vector<ComboPair> combo_only;
    unsigned int minMW = *std::min_element(predictedLoad.begin(), predictedLoad.end());
    for(int i = 0; i < rows; i++) {
        std::vector<Generator> combo;
        combo.reserve(size);
        int minSumMW = 0;
        for(int j = 0; j < size; j++) {
            if(bitCombos.at(i).at(j) == 0) {
                combo.push_back(offList.at(j));
            } else {
                minSumMW += static_cast<int>(onList.at(j).getMaxPowerOut());
                combo.push_back(onList.at(j));
            }
        }
        if(minSumMW > minMW) {
            combo_only.emplace_back(combo, 0);
        }
    }

    std::vector<std::future<double>> results;
    {
        ThreadPool pool(4);
        for(ComboPair& pair : combo_only) {
            results.emplace_back(pool.enqueue(Economic_Dispatch::calculate,pair.getCombo(), predictedLoad.at(0), pair.getCombo().size()));
        }
    }

    unsigned int cheapestCost = std::numeric_limits<unsigned int>::max();
    std::vector<std::pair<ComboPair, unsigned int>> combinations;
    for(int i = 0; i < results.size(); i++) {
        combo_only.at(i).setEconomicDispatch(results.at(i).get());
        combinations.emplace_back(combo_only.at(i), combo_only.at(i).getEconomicDispatch());
        if(combo_only.at(i).getEconomicDispatch() < cheapestCost) {
            cheapestCost = combo_only.at(i).getEconomicDispatch();
        }
    }

    auto t3 = std::chrono::high_resolution_clock::now();
    std::cout << "Combinations generated in " << std::chrono::duration_cast<std::chrono::microseconds>(t3 - t2).count() << " microseconds" << std::endl;

    /*
    std::vector<ComboPair> next;
    next.reserve(combinations.size());
    for(ComboPair pair : combinations) {
        next.push_back(pair);
    }
    */

    DynamicProgrammingAlgo dp;

    // initialize solution vector
    std::vector<std::pair<ComboPair, unsigned int>> solution;

    // initialize the first cheapest viable combo to start loop (assuming that generators are already running at load 0)
    std::pair<ComboPair, unsigned int> source_combo = dp.getCheapestViableSource(combinations, predictedLoad.at(0));
    solution.push_back(source_combo);

    std::cout << "Solution for Time Step " << 0 << " at load " << predictedLoad.at(0) << "MW:\n";
    for(Generator generator : source_combo.first.getCombo()) {
        std::cout << generator.getIsOn() << " ";
    }
    std::cout << "\nCost up to this timestep: " << source_combo.second << "\n\n";

    for(int i = 1; i < predictedLoad.size(); i++) {

        // calculate the economic dispatch for every combination for current load
        auto time1 = std::chrono::high_resolution_clock::now();
        std::vector<std::future<double>> currentResults;
        {
            ThreadPool pool(4);
            for(auto& pair : combinations) {
                currentResults.emplace_back(pool.enqueue(Economic_Dispatch::calculate,pair.first.getCombo(), predictedLoad.at(i), pair.first.getCombo().size()));
            }
        }
        for(int j = 0; j < currentResults.size(); j++) {
            combinations.at(j).first.setEconomicDispatch(currentResults.at(j).get());
        }
        auto time2 = std::chrono::high_resolution_clock::now();
        std::cout << "Dispatch Divide Time: " << std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count()*0.000001 << " seconds" << std::endl;

        // add the cheapest source + edge cost to every combination's running cost
        combinations = dp.addCheapestSE(combinations, source_combo);

        // find the next source combo
        source_combo = dp.cheapestForNode(combinations, predictedLoad.at(i));

        // add this source combo to the solution vector
        solution.push_back(source_combo);

        std::cout << "Solution for Time Step " << i << " at load " << predictedLoad.at(i) << "MW:\n";
        for(Generator generator : source_combo.first.getCombo()) {
            std::cout << generator.getIsOn() << " ";
        }
        std::cout << "\nCost up to this timestep: " << source_combo.second << "\n\n";

    }
    return 0;
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

