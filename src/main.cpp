// Driver Code
#include "generator.h"
#include "parser.h"

#include <iostream>
#include <random>

int main() {
    // Parse load MW data
    Parser<double> loadParser = Parser<double>("load_mw_no_time.csv");
    std::vector<double> predictedLoad= loadParser.loadData();

    // Set up the RNG
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 5);

    for (int i=0; i<16; ++i)
        std::cout << dist(mt) << "\n";

    return 0;
}