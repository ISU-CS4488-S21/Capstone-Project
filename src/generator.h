#ifndef UNIT_COMMITMENT_GENERATOR_H
#define UNIT_COMMITMENT_GENERATOR_H

class Generator {

private:
    double fuelCost, startUpCost, shutDownCost, economicDispatchCost, A, B, C;
    int maxPowerOut, minPowerOut;
    int isOn;
    enum GeneratorType {
        CoalFiredSteam,
        OilFiredSteam,
        SmallSub,
        LargeSub,
        OtherSteam,
    };

    GeneratorType type;


public:
    double sum(int x, int y);
    Generator(GeneratorType gt);

    double getFuelCost();
    double getStartUpCost();
    double getShutDownCost();
    double getBurnRate();
    int getPowerOut();
    int getIsOn();
    void turnOn();
    void turnOff();
    GeneratorType getGeneratorType();

};
#endif //UNIT_COMMITMENT_GENERATOR_H