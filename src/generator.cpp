#include "generator.h"

Generator::Generator(GeneratorType gt, double fCost, double stCost, double shCost, double bRate, int pOut) {
    type = gt;
    fuelCost = fCost;
    startUpCost = stCost;
    shutDownCost = shCost;
    burnRate = bRate;
    powerOut = pOut;
    isOn = false;
}

double Generator::getFuelCost() {
    return fuelCost;
}

double Generator::getStartUpCost() {
    return startUpCost;
}

double Generator::getShutDownCost() {
    return shutDownCost;
}

double Generator::getBurnRate() {
    return burnRate;
}

int Generator::getPowerOut() {
    return powerOut;
}

bool Generator::getIsOn() {
    return isOn;
}

void Generator::turnOn() {
    isOn = true;
}

void Generator::turnOff() {
    isOn = false;
}

Generator::GeneratorType Generator::getGeneratorType() {
    return type;
}

double Generator::sum(int x, int y){
    return x+y;
}
