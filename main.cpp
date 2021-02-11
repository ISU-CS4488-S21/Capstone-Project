// Driver Code

#include "src/generator.h"
#include "src/matrix.h"
#include "src/parser.h"
#include "src/ranking.h"

#include <iostream>

int main() {
    std::cout << "Testing Parser!" << std::endl;

    matrix M = Parser::loadData("./data/data.csv");
    Parser::displayData(M);
    std::cout << sum(2,4) << std::endl;
    return 0;
}
