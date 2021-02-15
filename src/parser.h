#ifndef UNIT_COMMITMENT_PARSER_H
#define UNIT_COMMITMENT_PARSER_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "matrix.h"

using namespace std;

class Parser {
private:
    const string filepath;
public:
    Parser() = default;
    static Matrix loadData(const string&);
};

#endif //UNIT_COMMITMENT_PARSER_H
