#ifndef UNIT_COMMITMENT_GENERATOR_H
#define UNIT_COMMITMENT_GENERATOR_H

class Generator {

    private:
        double fuelCost{};
        double startUpCost{};
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
        Generator(double fuelCost, double startUpCost, GeneratorType type);
        double getFuelCost();
        double getStartUpCost();
};
#endif //UNIT_COMMITMENT_GENERATOR_H
