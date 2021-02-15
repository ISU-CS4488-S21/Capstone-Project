// Driver Code

#include "generator.h"
#include "matrix.h"
#include "parser.h"
#include "ranking.h"

#include <iostream>

int main() {
    //std::cout << "Reading system_load_mw.csv" << std::endl;
    Parser parser = Parser("system_load_mw.csv");
    Matrix system_load = parser.loadData();
    system_load.print();
    return 0;
}