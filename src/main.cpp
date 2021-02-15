// Driver Code

#include "generator.h"
#include "matrix.h"
#include "parser.h"
#include "ranking.h"

#include <iostream>

int main() {
    std::cout << "Reading system_load_mw.csv" << std::endl;
    Matrix system_load = Parser::loadData("./data/system_load_mw.csv");
    system_load.print();
    return 0;
}
