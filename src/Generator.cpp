#include "Generator.h"
#include <cmath>

/**
 * @author Marcus Goeckner
 *
 * Generator class to represent different generator types and their respective costs
 * power characteristics
 */

/**
 * Creates a new instance of a generator
 * @param gt: the type of generator (see enum GeneratorType in generator.h)
 * @param powerState: indicate if generator should be on or off when created
 */

Generator::Generator(){}
Generator::Generator(GeneratorType gt, bool powerState) {
    type = gt;
    isOn = powerState;

    // economicDispatchCost currently uses maxPowerOut
    // maxPowerOut and minPowerOut are in MW
    if (gt == CoalFiredSteam) {
        fuelCost = 1;
        startUpCost = 64;
        shutDownCost = 25;
        maxPowerOut = 600;
        minPowerOut = 150;
        A = 510;
        B = 7.2;
        C = 0.00142;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    } else if (gt == OilFiredSteam){
        fuelCost = 1;
        startUpCost = 46;
        shutDownCost = 15;
        maxPowerOut = 400;
        minPowerOut = 100;
        A = 310;
        B = 7.85;
        C = 0.00194;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    } else if (gt == SmallSub) {
        fuelCost = 1;
        startUpCost = 112;
        shutDownCost = 5;
        maxPowerOut = 100;
        minPowerOut = 20;
        A = 80;
        B = 8;
        C = 0.024;
        economicDispatchCost = 0;
    } else if (gt == LargeSub) {
        fuelCost = 1;
        startUpCost = 78;
        shutDownCost = 10;
        maxPowerOut = 350;
        minPowerOut = 45;
        A = 225;
        B = 8.4;
        C = 0.0025;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    } else if (gt == OtherSteam) {
        fuelCost = 1;
        startUpCost = 48;
        shutDownCost = 20;
        maxPowerOut = 200;
        minPowerOut = 20;
        A = 400;
        B = 5;
        C = 0.01;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    }

}

// getters and setters

double Generator::getFuelCost() const {
    return fuelCost;
}

double Generator::getStartUpCost() const {
    return startUpCost;
}

double Generator::getShutDownCost() const {
    return shutDownCost;
}

double Generator::getB() const{
    return B;
}

double Generator::getC() const{
    return C;
}
int Generator::getMinPowerOut() const {
    return minPowerOut;
}

int Generator::getMaxPowerOut() const {
    return maxPowerOut;
}

bool Generator::getIsOn() const {
    return isOn;
}

void Generator::turnOn() {
    isOn = true;
}

void Generator::turnOff() {
    isOn = false;
}

GeneratorType Generator::getGeneratorType() {
    return type;
}


double Generator::sum(int x, int y){
    return x+y;
}

double Generator::getBurnRate() {
    return 0;
}
