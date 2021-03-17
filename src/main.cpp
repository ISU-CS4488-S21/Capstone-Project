// Driver Code
#include "generator.h"
#include "parser.h"

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

    // Verify that genCombos contains sub-vectors containing each possible off/on combination
    for(const auto& combo : genCombos) {
        for(auto gen : combo) {
            std::cout << "gt: " << gen.getGeneratorType() << " on: " << gen.getIsOn() << '\t';
        }
        std::cout << std::endl;
    }

    return 0;
}