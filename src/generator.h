#ifndef UNIT_COMMITMENT_GENERATOR_H
#define UNIT_COMMITMENT_GENERATOR_H

class Generator {

    private:
        double fuelCost, startUpCost, shutDownCost, burnRate;
        int powerOut;
        bool isOn;
        enum GeneratorType {
            Coal,
            Nuclear,
            Hydro,
            Wind,
            Solar,
        };

        GeneratorType type;


    public:
        double sum(int x, int y);
        Generator(GeneratorType gt, double fCost, double stCost, double shCost, double bRate, int pOut);

        double getFuelCost();
        double getStartUpCost();
        double getShutDownCost();
        double getBurnRate();
        int getPowerOut();
        bool getIsOn();
        void turnOn();
        void turnOff();
        GeneratorType getGeneratorType();

};
#endif //UNIT_COMMITMENT_GENERATOR_H
