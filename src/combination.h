#ifndef UNIT_COMMITMENT_COMBINATION_H
#define UNIT_COMMITMENT_COMBINATION_H

#include "economic_dispatch.h"

class ComboPair {
private:
    std::vector<Generator> combo;
    double economicDispatch;
    double maxPowerOut;
    double minPowerOut;
public:
    ComboPair(std::vector<Generator> list, double cost) : combo(std::move(list)), economicDispatch(cost) {
        for (Generator gen: list) {
            minPowerOut += gen.getMinPowerOut();
        }
        for (Generator gen: list) {
            maxPowerOut += gen.getMaxPowerOut();
        }

    }
    std::vector<Generator> & getCombo() { return combo; }
    double getEconomicDispatch() const { return economicDispatch; }
    void setEconomicDispatch(double cost) { economicDispatch = cost; }
    double getMaxPowerOut() { return maxPowerOut; }
    double getMinPowerOut() { return minPowerOut; }
};

#endif //UNIT_COMMITMENT_COMBINATION_H