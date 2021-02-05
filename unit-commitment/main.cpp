// Driver Code

#include "generator.h"
#include "matrix.h"
#include "parser.h"
#include "ranking.h"

#include <iostream>

int main() {
    std::cout << "Testing Parser!" << std::endl;

    matrix M = Parser::loadData("./data/data.csv");
    Parser::displayData(M);

    return 0;
}
