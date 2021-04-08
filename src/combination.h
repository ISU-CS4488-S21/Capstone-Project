#ifndef UNIT_COMMITMENT_COMBINATION_H
#define UNIT_COMMITMENT_COMBINATION_H

#include "economic_dispatch.h"

class ComboPair {
private:
    std::vector<Generator> combo;
    std::vector<double> lambda;
public:
    ComboPair(std::vector<Generator> combo, std::vector<double> lambda) : combo(combo), lambda(lambda) {}
    std::vector<Generator> getCombo() { return combo; }
    std::vector<double> getLambda() { return lambda; }
};

#endif //UNIT_COMMITMENT_COMBINATION_H