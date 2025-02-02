//
// Created by Deepson Khadka on 4/4/21.
//
#include <vector>
#include <iostream>
#include <limits>
#include "economic_dispatch.h"
#include "generator.h"
#include "combination.h"

///Dynamic Programming class
class DynamicProgrammingAlgo{

public:
    /// Function to get the edge cost between generator combos
    int getEdgeCost(std::vector<Generator> g1, std::vector<Generator> g2){
        int eCost = 0;
        for(int i = 0; i < g1.size(); i++){
            if(g1[i].getIsOn() != g2[i].getIsOn()){
                if(g1[i].getIsOn() == false){
                    eCost += g1[i].getStartUpCost();
                }
                else {
                    eCost += g1[i].getShutDownCost();
                }
            }
        }
        return eCost;
    }

     /// Gets the cheapest path to any generator combo from a given source node.
    std::pair <ComboPair,unsigned int> cheapestForNode(std::vector<std::pair<ComboPair, unsigned int>> pCombos, double load){
        std::pair<ComboPair, unsigned int> out(pCombos[pCombos.size() - 1].first, pCombos[pCombos.size() - 1].second);
         bool viableFound = false;
        for (int i = 0; i < pCombos.size(); i++) {
            if (pCombos[i].first.getMaxPowerOut() >= load && pCombos[i].first.getMinPowerOut() <= load || out.second == 0){
                if (pCombos[i].second < out.second || out.second == 0) {
                    out.second = pCombos[i].second;
                    out.first = pCombos[i].first;
                    viableFound = true;
                }
            }
        }
         if (!viableFound) {
             for (std::pair<ComboPair, unsigned int> pair : pCombos) {
                 if (pair.first.getEconomicDispatch() < out.first.getEconomicDispatch()) {
                     out = pair;
                 }
             }
         }
        return out;
    }

    /**
     * searches for the cheapest viable combination given a load
     *
     * @param pairs: vector of generator combinations and their running cost
     * @param load: the power load in MW for the cheapest combination to satisfy
     * @return: the cheapest combo
     */
    std::pair<ComboPair, unsigned int> getCheapestViableSource(std::vector<std::pair<ComboPair, unsigned int>> pairs, unsigned int load) {
        std::pair<ComboPair, unsigned int> cheapestPair = std::pair<ComboPair, unsigned int>(pairs.at(pairs.size() - 1).first, pairs.at(pairs.size() - 1).second);
        bool viableFound = false;
        for (std::pair<ComboPair, unsigned int> pair : pairs) {
            if ((pair.first.getMaxPowerOut() >= load && pair.second < cheapestPair.second) || cheapestPair.second == 0) {
                cheapestPair = pair;
                viableFound = true;
            }
        }
        if (!viableFound) {
            for (std::pair<ComboPair, unsigned int> pair : pairs) {
                if (pair.first.getEconomicDispatch() < cheapestPair.first.getEconomicDispatch()) {
                    cheapestPair = pair;
                }
            }
        }
        return cheapestPair;
    }

    ///Output a vector of pairs that consists of the generator combo path and the overall cost.
    std::vector<std::pair<ComboPair,unsigned int>> cheapestRoutes(std::vector<std::pair<ComboPair, unsigned int>> source, std::vector<std::pair<ComboPair, unsigned int>> next,double load){
        std::vector<std::pair<ComboPair,unsigned int>> out;
        for(int i =0; i < source.size(); i++){
            out.push_back(cheapestForNode(next,load));
        }
        return out;
    }

    /**
     * adds cheapest source + edge to every current state based on previous cheapest
     *
     * @param combinations: the vector of pairs of current state's combinations and their costs
     * @param source: the cheapest viable source
     * @return: a new vector containing the combinations and their updated costs
     */
    std::vector<std::pair <ComboPair,unsigned int>> addCheapestSE(std::vector<std::pair<ComboPair, unsigned int>> combinations, std::pair<ComboPair, unsigned int> source) {
        std::vector<std::pair<ComboPair,unsigned int>> newStates;
        for (std::pair<ComboPair, unsigned int> pair : combinations) {
            pair.second += source.first.getEconomicDispatch() + getEdgeCost(source.first.getCombo(), pair.first.getCombo());
            newStates.push_back(pair);
        }
        return newStates;
    }
};


