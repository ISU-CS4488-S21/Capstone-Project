#include "generator.h"
#include <cmath>
#include <stdlib.h>
#include <random>

/**
 * @author Marcus Goeckner
 *
 * Generator class to represent different fixtureGenerator types and their respective costs
 * power characteristics
 */

/**
 * Creates a new instance of a fixtureGenerator
 * @param gt: the type of fixtureGenerator (see enum GeneratorType in fixtureGenerator.h)
 * @param powerState: indicate if fixtureGenerator should be on or off when created
 */
Generator::Generator(){};
Generator::Generator(GeneratorType gt, bool powerState) {
    type = gt;
    isOn = powerState;

    // economicDispatchCost currently uses maxPowerOut
    // maxPowerOut and minPowerOut are in MW

    // +- 50 MW for generating random power-outs within accurate range based off found data, below 50 is +- 5
    // +- 20 for generating costs above 50, below 50 is +- 5
    if (gt == CoalFiredSteam) {
        fuelCost = 1;
        startUpCost = 2 * randNum(44, 84); //base: 64
        shutDownCost = 2 * randNum(20, 30); //base: 25
        maxPowerOut = randNum(550, 650); //base: 600
        minPowerOut = randNum(300, 400); //base: 350
        A = 510;
        B = 7.2;
        C = 0.00142;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    } else if (gt == OilFiredSteam){
        fuelCost = 1;
        startUpCost = 2 * randNum(41, 51); //base: 46;
        shutDownCost = randNum(1, 4) * randNum(10, 20); //base: 15
        maxPowerOut = randNum(350, 450); //base: 400;
        minPowerOut = randNum(200, 300); //base: 250;
        A = 310;
        B = 7.85;
        C = 0.00194;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    } else if (gt == SmallSub) {
        fuelCost = 1;
        startUpCost = 2 * randNum(92, 132); //base: 112
        shutDownCost = 2 * randNum(1, 11); //base: 6
        maxPowerOut = randNum(50, 150);//base: 100
        minPowerOut = randNum(25, 35); //base: 30
        A = 80;
        B = 8;
        C = 0.024;
        economicDispatchCost = 0;
    } else if (gt == LargeSub) {
        fuelCost = 1;
        startUpCost = 2 * randNum(58, 98); //base: 78
        shutDownCost = 2 * randNum(5, 15); //base: 10
        maxPowerOut = randNum(300, 400); //base: 350
        minPowerOut = randNum(150, 250); //base: 100
        A = 225;
        B = 8.4;
        C = 0.0025;
        economicDispatchCost = A + B*maxPowerOut + C*pow(maxPowerOut, 2);
    } else if (gt == OtherSteam) {
        fuelCost = 1;
        startUpCost = 2 * randNum(43, 53); //base: 48
        shutDownCost = 2 * randNum(25, 35); //base: 20
        maxPowerOut = randNum(150, 250); //base: 200
        minPowerOut = randNum(75, 125); //base: 100
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
double Generator::getMinPowerOut() const {
    return minPowerOut;
}

double Generator::getMaxPowerOut() const {
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
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}
