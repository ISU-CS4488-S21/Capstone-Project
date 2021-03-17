// Driver Code
#include "generator.h"
#include "parser.h"

#include <iostream>

int main() {
    Parser<double> loadParser = Parser<double>("load_mw_no_time.csv");
    std::vector<double> predictedLoad= loadParser.loadData();

    for(auto num : predictedLoad) {
        std::cout << num << std::endl;
    }

    return 0;
}