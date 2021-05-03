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
// A function that removes the Off Generators from a combination, and leaves only the on ones.
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
// Divide provides a structure to call the Lambda function. It uses the onGenerators function to narrow
// down to the on generators. The major benefit of this is that is divides the combination in half to provide faster computation.
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
// if the size of vectors is larger than 1, divide in half and perform "merge"
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
// call Merge function to get lambda cost
        out = merge(load,firstHalf,secondHalf);
    }
    return out;
}

// this function takes two combinations of vectors, calculates the cheapest operating cost.
double Economic_Dispatch::merge(double load, std::vector<Generator> &g1, std::vector<Generator> &g2) {
    double mLoad = load;
    double out = std::numeric_limits<int>::max();
// a while loop is used to check the cost at all available loads. The costs are compared and the cheapest is selected.
    while(load > 0){
// use check bound to not calculate any loads out of range.
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
    //   double out;

// create a pair out of an array of generators to hold B and C values.
// this was done very early and may be an easy change for speed.

//    for(auto elem : generators){
//        gen.push_back(std::make_pair<double, double>(elem.getB(), elem.getC()));
//    }

    int maxLoad = load;
    double temp;
    double min = std::numeric_limits<int>::max();
    double g2,g1;
    double load_sq = pow(load, 2);
    double max_sq = pow(maxLoad-load,2);
// if an array of 1 generator then just return the ED of that gen
    if(index == 1){
        //return gen[0].first*load + gen[0].second*pow(load,2);
        return generators[0].getB()*load + generators[0].getC()+load_sq;
    }
// compare two generators at varying loads to get cheapest option between them.
    if(index < 1){
        //The final branch of the generator tree to return optimized cost.
        while(load > 0){
            // g1 = gen[0].first*load + gen[0].second*pow(load,2);
            // g2 = gen[1].first*load + gen[1].second*pow((maxLoad-load),2);
            g1 = generators[0].getB()*load + generators[0].getC()*load_sq;
            g2 = generators[1].getB()*load + generators[1].getC()*max_sq;
            temp = (g1) + (g2);
            if(min > temp){
                min = (g1) + (g2);
            }
            load -= 1;
        }
    }
// the recursive part of the function. Compare the outermost generator with a combination of the rest.
// the recursion continues until there is just one pair of generators to find the cost.
    else{
        // Determine the cost at every possible load value.
        // Recursively cal the function to branch off every cost possibility
        // at a specific load comparison.
        while(load > 0){
            //g1 = gen[index-1].first*load + gen[index-1].second*pow(load,2);
            g2 = lambdaFunction(maxLoad - load,generators,index-2);
            g1 = generators[index - 1].getB()*load + generators[index - 1].getC()*load_sq;
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
