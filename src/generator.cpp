#include "generator.h"
#include <cmath>
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
        startUpCost =  randNum(4, 9) * randNum(44, 84); //base: 64
        shutDownCost = randNum(2, 9) * randNum(20, 30); //base: 25
        maxPowerOut = randNum(550, 650); //base: 600
        minPowerOut = randNum(100, 200); //base: 150
        A = 510;
        B = 7.2;
        C = 0.00142;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    } else if (gt == OilFiredSteam){
        fuelCost = 1;
        startUpCost = randNum(2, 4) * randNum(41, 51); //base: 46;
        shutDownCost = randNum(1, 4) * randNum(10, 20); //base: 15
        maxPowerOut = randNum(350, 450); //base: 400;
        minPowerOut = randNum(50, 150); //base: 100;
        A = 310;
        B = 7.85;
        C = 0.00194;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    } else if (gt == SmallSub) {
        fuelCost = 1;
        startUpCost = randNum(2, 6) * randNum(92, 132); //base: 112
        shutDownCost = randNum(1, 5) * randNum(1, 11); //base: 6
        maxPowerOut = randNum(50, 150);//base: 100
        minPowerOut = randNum(15, 25); //base: 20
        A = 80;
        B = 8;
        C = 0.024;
        economicDispatchCost = 0;
    } else if (gt == LargeSub) {
        fuelCost = 1;
        startUpCost = randNum(4, 9) * randNum(58, 98); //base: 78
        shutDownCost = randNum(2, 9) * randNum(5, 15); //base: 10
        maxPowerOut = randNum(300, 400); //base: 350
        minPowerOut = randNum(40, 50); //base: 45
        A = 225;
        B = 8.4;
        C = 0.0025;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    } else if (gt == OtherSteam) {
        fuelCost = 1;
        startUpCost = randNum(2, 5) * randNum(43, 53); //base: 48
        shutDownCost = randNum(1, 4) * randNum(25, 35); //base: 20
        maxPowerOut = randNum(150, 250); //base: 200
        minPowerOut = randNum(15, 25); //base: 20
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

/**
 * generates a random number in the range [min, max]
 * @param min: lower bound for the range
 * @param max: upper bound for the range
 * @return: a random number between min and max (inclusive)
 */
int Generator::randNum(int min, int max) {
    return min + (rand() % static_cast<int>(max - min + 1));
}
