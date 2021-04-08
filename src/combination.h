#ifndef UNIT_COMMITMENT_COMBINATION_H
#define UNIT_COMMITMENT_COMBINATION_H

#include "economic_dispatch.h"

class ComboPair {
private:
    std::vector<Generator> combo;
    double lambda;
public:
    ComboPair(std::vector<Generator> list, double cost) : combo(std::move(list)), lambda(cost) {}
    std::vector<Generator> getCombo() { return combo; }
    double getLambda() const { return lambda; }
    void setLambda(double cost) { lambda = cost; }
};

#endif //UNIT_COMMITMENT_COMBINATION_H