#ifndef UNIT_COMMITMENT_GENERATOR_H
#define UNIT_COMMITMENT_GENERATOR_H

enum GeneratorType {
    CoalFiredSteam,
    OilFiredSteam,
    SmallSub,
    LargeSub,
    OtherSteam,
};

class Generator {
private:
    double fuelCost, startUpCost, shutDownCost, economicDispatchCost, A, B, C;
    int maxPowerOut, minPowerOut;
    bool isOn;
    GeneratorType type;

public:
    double sum(int x, int y);
    Generator(GeneratorType gt, bool powerState);
    double getFuelCost() const;
    double getStartUpCost() const;
    double getShutDownCost() const;
    double getBurnRate();
    double getB() const;
    double getC() const;
    int getMaxPowerOut() const;
    int getMinPowerOut() const;
    bool getIsOn() const;
    void turnOn();
    void turnOff();
    GeneratorType getGeneratorType();
};
#endif //UNIT_COMMITMENT_GENERATOR_H
