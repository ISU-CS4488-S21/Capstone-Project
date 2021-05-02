//
// Created by Nate Shubert on 3/17/21.
//
#include "economic_dispatch.h"
#include "generator.h"
#include <limits>
#include <utility>
#include <vector>
#include <cmath>

Economic_Dispatch::Economic_Dispatch(){
    skippedLoads = 0;
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

double Economic_Dispatch::divide(double load, std::vector<Generator> &generators) {
    std::vector<Generator> onGens;
    for(const auto& combo : generators){
        if(combo.getIsOn()){
            onGens.push_back(combo);
        }
    }
    double mLoad = load;
    int out = std::numeric_limits<int>::max();
    if(onGens.size() == 0){
        return 0;
    }
    else if (onGens.size() == 1){
        //if(onGens[0].getMinPowerOut() <= load && onGens[0].getMaxPowerOut() >= load){
            return onGens[0].getB()*load + onGens[0].getC()*pow(load,2);
        //}
        //else{
         //   return std::numeric_limits<int>::max();
       // }
    }
    else{
        int half = trunc(onGens.size()/2);
        std::vector<Generator> firstHalf;
        std::vector<Generator> secondHalf;
        // split generators
        for(int i = 0; i<onGens.size(); i++){
            if(i < half){
                firstHalf.push_back(onGens[i]);
            }
            else{
                secondHalf.push_back(onGens[i]);
            }
        }
        out = merge(load,firstHalf,secondHalf);
    }
    return out;
}

double Economic_Dispatch::merge(double load, std::vector<Generator> &g1, std::vector<Generator> &g2) {
    double mLoad = load;
    double out = std::numeric_limits<int>::max();
    while(load > 0){
        if (checkBound(load, const_cast<std::vector<Generator> &>(g1)) && checkBound(load, const_cast<std::vector<Generator> &>(g2))){
            double one = lambdaFunction(load,g1,g1.size());
            double two = lambdaFunction(mLoad - load,g2,g2.size());
            //double one = divide(load,firstHalf);
            //double two = divide(mLoad - load,secondHalf);
            double split =  one + two;
            if (split < out){
                out = split;
            }
        }
        load -= 20;
    }
    return out;
}

// This function was created to limit the load values used in the while loops.
// It checks to make sure that the load is within the max and min capacity of the generators.
bool Economic_Dispatch::checkBound(double load, std::vector<Generator> &g1) {
    double totalMax = 0;
    double totalMin = 0;
    for(auto gen: g1){
        totalMax += gen.getMaxPowerOut();
        totalMin += gen.getMinPowerOut();
    }
    if(load > totalMax || load < totalMin){
        skippedLoads += 1;
        return false;
    }
    else{
        testedLoads += 1;
        return true;
    }
}
// A function to find the minimized cost between a set of generators at
// every possible load.
double Economic_Dispatch::lambdaFunction(double load, const std::vector<Generator>& generators, int index) {
    std::vector<std::pair<double,double>> gen;
    double out;
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
        // Recursively cal the function to branch off every cost possibility
        // at a specific load comparison.
        while(load > 0){
            g1 = gen[index-1].first*load + gen[index-1].second*pow(load,2);
            g2 = lambdaFunction(maxLoad - load,generators,index-2);
            temp = g1 + g2;
            if(min > temp){
                min = g1 + g2;
            }
            load -= 50;
        }
    }
    return min;
}

int Economic_Dispatch::getSkipCounter() const {
    return skippedLoads;
}
int Economic_Dispatch::getTestedCounter() const {
    return testedLoads;
}
