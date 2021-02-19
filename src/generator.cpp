#include "generator.h"

Generator::Generator(double fuelCost, double startUpCost, GeneratorType type) {
    this->fuelCost = fuelCost;
    this->startUpCost = startUpCost;
    this->type = type;
}

double Generator::getFuelCost() {
    return fuelCost;
}

double Generator::getStartUpCost() {
    return startUpCost;
}

double Generator::sum(int x, int y){
    return x+y;
}
