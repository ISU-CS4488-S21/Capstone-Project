#include "generator.h"
#include <cmath>
#include <ctime>
#include <stdlib.h>

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
Generator::Generator(GeneratorType gt, bool powerState) {
    type = gt;
    isOn = powerState;

    // economicDispatchCost currently uses maxPowerOut
    // maxPowerOut and minPowerOut are in MW

    // +- 50 MW for generating random power-outs within accurate range based off found data, below 50 is +- 5
    // +- 20 for generating costs above 50, below 50 is +- 5
    if (gt == CoalFiredSteam) {
        fuelCost = 1;
        startUpCost =  rand() % 41 + 44; //base: 64
        shutDownCost = rand() % 11 + 20; //base: 25
        maxPowerOut = rand() % 101 + 550 ; //base: 600
        minPowerOut = rand() % 101 + 100; //base: 150
        A = 510;
        B = 7.2;
        C = 0.00142;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    } else if (gt == OilFiredSteam){
        fuelCost = 1;
        startUpCost = rand() % 11 + 41; //base: 46;
        shutDownCost = rand() % 11 + 10; //base: 15
        maxPowerOut = rand() % 101 + 350; //base: 400;
        minPowerOut = rand() % 101 + 50; //base: 100;
        A = 310;
        B = 7.85;
        C = 0.00194;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    } else if (gt == SmallSub) {
        fuelCost = 1;
        startUpCost = rand() % 41 + 92; //base: 112
        shutDownCost = rand() % 11 + 1; //base: 6
        maxPowerOut = rand() % 101 + 50;//base: 100
        minPowerOut = rand() % 11 + 15; //base: 20
        A = 80;
        B = 8;
        C = 0.024;
        economicDispatchCost = 0;
    } else if (gt == LargeSub) {
        fuelCost = 1;
        startUpCost = rand() % 41 + 58; //base: 78
        shutDownCost = rand() % 11 + 5; //base: 10
        maxPowerOut = rand() % 101 + 300; //base: 350
        minPowerOut = rand() % 11 + 40; //base: 45
        A = 225;
        B = 8.4;
        C = 0.0025;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    } else if (gt == OtherSteam) {
        fuelCost = 1;
        startUpCost = rand() % 11 + 43; //base: 48
        shutDownCost = rand() % 11 + 15; //base: 20
        maxPowerOut = rand() % 101 + 150; //base: 200
        minPowerOut = rand() % 11 + 15; //base: 20
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
