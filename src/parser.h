#ifndef UNIT_COMMITMENT_PARSER_H
#define UNIT_COMMITMENT_PARSER_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
using vec = vector<double>;
using matrix = vector<vec>;

class Parser {
private:
public:
    Parser() {};
    static matrix loadData(const string&);
    static void displayData(const matrix &M);
};

#endif //UNIT_COMMITMENT_PARSER_H
