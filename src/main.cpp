// Driver Code

//#include "generator.h"
#include "matrix.h"
//#include "parser.h"
//#include "ranking.h"

#include <iostream>

int main() {
    std::cout << "Reading system_load_mw.csv" << std::endl;
    //matrix M = Parser::loadData("./data/system_load_mw.csv");
    Matrix system_load = Matrix(2, 2);
    std::cout << system_load.rows() << std::endl;
    std::cout << system_load.cols() << std::endl;
    std::cout << system_load.getValue(0,0) << std::endl;
    system_load.setValue(3, 3, 100);
    std::cout << system_load.getValue(0,0) << std::endl;
    return 0;
}
