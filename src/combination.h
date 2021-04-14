#ifndef UNIT_COMMITMENT_COMBINATION_H
#define UNIT_COMMITMENT_COMBINATION_H

#include "economic_dispatch.h"

class ComboPair {
private:
    std::vector<Generator> combo;
    double economicDispatch;
public:
    ComboPair(std::vector<Generator> list, double cost) : combo(std::move(list)), economicDispatch(cost) {}
    std::vector<Generator> & getCombo() { return combo; }
    double getEconomicDispatch() const { return economicDispatch; }
    void setEconomicDispatch(double cost) { economicDispatch = cost; }
};

#endif //UNIT_COMMITMENT_COMBINATION_H