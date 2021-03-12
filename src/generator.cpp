#include "generator.h"
#include<cmath>

Generator::Generator(GeneratorType gt, int powerState) {
    type = gt;
    isOn = powerState;

    // economicDispatchCost currently uses maxPowerOut
    if (gt == CoalFiredSteam) {
        fuelCost = 1;
        startUpCost = 0;
        shutDownCost = 0;
        maxPowerOut = 0;
        minPowerOut = 0;
        A = 0;
        B = 0;
        C = 0;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    } else if (gt == OilFiredSteam){
        fuelCost = 1;
        startUpCost = 0;
        shutDownCost = 0;
        maxPowerOut = 0;
        minPowerOut = 0;
        A = 0;
        B = 0;
        C = 0;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    } else if (gt == SmallSub) {
        fuelCost = 1;
        startUpCost = 0;
        shutDownCost = 0;
        maxPowerOut = 0;
        minPowerOut = 0;
        A = 0;
        B = 0;
        C = 0;
        economicDispatchCost = 0;
    } else if (gt == LargeSub) {
        fuelCost = 1;
        startUpCost = 0;
        shutDownCost = 0;
        maxPowerOut = 0;
        minPowerOut = 0;
        A = 0;
        B = 0;
        C = 0;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    } else if (gt == OtherSteam) {
        fuelCost = 1;
        startUpCost = 0;
        shutDownCost = 0;
        maxPowerOut = 0;
        minPowerOut = 0;
        A = 0;
        B = 0;
        C = 0;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    }

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

int Generator::getMinPowerOut() {
    return minPowerOut;
}

int Generator::getMaxPowerOut() {
    return maxPowerOut;
}

int Generator::getIsOn() {
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
