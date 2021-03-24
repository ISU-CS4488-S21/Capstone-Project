//
// Created by Nate Shubert on 3/17/21.
//
#include "economic_dispatch.h"
#include <generator.h>
#include <limits>
#include <utility>
#include <vector>
#include <cmath>

Economic_Dispatch::Economic_Dispatch(){

}

std::vector<std::vector<Generator>> & Economic_Dispatch::onGenerators(std::vector<std::vector<Generator>> &generators) {
    // Narrow down to only on generators
    std::vector<std::vector<Generator>> onGenCombos;
    std::vector<Generator> onGens;
    for(const auto& combo : generators){
        for(auto gen : combo){
            if(gen.getIsOn()){
                onGens.push_back(gen);
            }
        }
        if(onGens.size() > 0){
            onGenCombos.push_back(onGens);
        }
        onGens.clear();
    }
    return onGenCombos;
}
double Economic_Dispatch::divide(double load, const std::vector<Generator> &generators) {
    double mLoad = load;
    int out = std::numeric_limits<int>::max();
    if(generators.size() == 0){
        return 0;
    }
    else if (generators.size() == 1){
        return generators[0].getB()*load + generators[0].getC()*pow(load,2);
    }
    else{
        int half = trunc(generators.size()/2);
        std::vector<Generator> firstHalf;
        std::vector<Generator> secondHalf;
        // split generators
        for(int i = 0; i<generators.size(); i++){
            if(i < half){
                firstHalf.push_back(generators[i]);
            }
            else{
                secondHalf.push_back(generators[i]);
            }
        }
        while(load > 0){
            double one = lambdaFunction(load,firstHalf,firstHalf.size());
            double two = lambdaFunction(mLoad - load,secondHalf,secondHalf.size());
            double split =  one + two;
            if (split < out){
                out = split;
            }
            load -= 100;
        }
    }
    return out;
}
// A function to find the minimized cost between a set of generators at
// every possible load.
double Economic_Dispatch::lambdaFunction(double load, const std::vector<Generator>& generators, int index) {
    std::vector<std::pair<double,double>> gen;
    double out;
    gen.reserve(generators.size());
    for(auto elem : generators){
        gen.push_back(std::make_pair<double, double>(elem.getB(), elem.getC()));
    }
    int maxLoad = load;
    double temp;
    double min = std::numeric_limits<int>::max();
    double g2,g1;
    if(index == 1){
        return gen[0].first*load + gen[0].second*pow(load,2);
    }
    if(index < 1){
        //The final branch of the generator tree to return optimized cost.
        while(load > 0){
            g1 = gen[0].first*load + gen[0].second*pow(load,2);
            g2 = gen[1].first*load + gen[1].second*pow((maxLoad-load),2);
            temp = (g1) + (g2);
            if(min > temp){
                min = (g1) + (g2);
            }
            load -= 1;
        }
    }
    else{
        // Determine the cost at every possible load value.
        // Recursively call the function to branch off every cost possibility
        // at a specific load comparison.
        while(load > 0){
            g1 = gen[index-1].first*load + gen[index-1].second*pow(load,2);
            g2 = lambdaFunction(maxLoad - load,generators,index-2);
            temp = g1 + g2;
            if(min > temp){
                min = g1 + g2;
            }
            load -= 100;
        }
    }
    return min;
}
