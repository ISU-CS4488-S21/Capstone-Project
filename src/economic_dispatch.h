//
// Created by Nate Shubert on 3/17/21.
//
#include <string>
#include <vector>
#include <generator.h>

#ifndef UNIT_COMMITMENT_ECONOMIC_DISPATCH_H
#define UNIT_COMMITMENT_ECONOMIC_DISPATCH_H

class Economic_Dispatch{
private:

public:
    Economic_Dispatch();
    double lambdaFunction(double load, const std::vector<Generator>& generators, int index);
    double divide(double load, const std::vector<Generator>& generators);
    std::vector<std::vector<Generator>>& onGenerators(std::vector<std::vector<Generator>>& generators);
};

#endif //UNIT_COMMITMENT_ECONOMIC_DISPATCH_H
