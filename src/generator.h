#ifndef UNIT_COMMITMENT_GENERATOR_H
#define UNIT_COMMITMENT_GENERATOR_H


/**
 * @author Marcus Goeckner
 */
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
    double maxPowerOut, minPowerOut;
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
    double getMaxPowerOut() const;
    double getMinPowerOut() const;
    bool getIsOn() const;
    void turnOn();
    void turnOff();
    int randNum(int min, int max);
    GeneratorType getGeneratorType();
};
#endif //UNIT_COMMITMENT_GENERATOR_H
