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
    int skippedLoads;
    int testedLoads;
public:
    Economic_Dispatch();
    int getSkipCounter() const;
    int getTestedCounter() const;
    double lambdaFunction(double load, const std::vector<Generator>& generators, int index);
    double divide(double load, std::vector<Generator>& generators);
    double merge(double load, std::vector<Generator>& g1,std::vector<Generator>& g2);
    bool checkBound(double load, std::vector<Generator>& g1);
    std::vector<std::vector<Generator>>& onGenerators(std::vector<std::vector<Generator>>& generators);
    static double calculate(std::vector<Generator>& generators, double load, int index);
};

#endif //UNIT_COMMITMENT_ECONOMIC_DISPATCH_H
