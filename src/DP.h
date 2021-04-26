//
// Created by Deepson Khadka on 4/4/21.
//
#include <vector>
#include <iostream>
#include <limits>
#include "economic_dispatch.h"
#include "generator.h"
#include "combination.h"

//Dynamic Programming
class DynamicProgrammingAlgo{

public:
    ///Adds cheapest S+E to determine with current state
    ///Can be modified baseed on edges and sources data structures
    std::vector<std::vector<unsigned int>> SourcePlusEdge2D(std::vector<std::vector<unsigned int>> edges, std::vector<std::vector<unsigned int>> sources,std::vector<std::vector<int>> combStatesCosts){

        for (int i = 0; i <edges.at(0).size() ; ++i) {
            for (int j = 0; j <edges.at(1).size(); ++j) {
                ///(s+E)*state(0,1)
                edges[i][j]=(edges[i][j]+sources[i][j])*combStatesCosts[i][j];
            }
        }
        ///New total cost stored as edgee
        return edges;
    }


    ///Compares all possible source and edges
    ///Needs to work on

    std::vector<unsigned int> GetCheapestColumn(std::vector<std::vector<unsigned int>> addedCosts2D) {
        std::vector<unsigned int> tempCosts;
        int prevCost=0;

        for (int i = 0; i < addedCosts2D.at(0).size() ; ++i) {

            for (int j = 0; j < addedCosts2D.at(1).size() ; ++j) {
                prevCost+=addedCosts2D[i][j];
            }
            tempCosts.push_back(prevCost);
            prevCost=0;
        }
        return tempCosts;
    }

    ///SImply display function for testing
    void DisplaySPlusE(std::vector<std::vector<unsigned int>> input1, std::vector<std::vector<unsigned int>> input2, std::vector<std::vector<int>> input3){
        int citiesLength=input1.size();
        for (int i = 0; i <citiesLength ; ++i) {
            std::cout<<std::endl;
            for (int j = 0; j <citiesLength ; ++j) {
                std::cout << SourcePlusEdge2D(input1, input2, input3)[i][j] << ", ";
            }
            std::cout<<std::endl;
        }
    }

    // Function to get the edge cost between generator combos
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

     // Gets the cheapest path to any generator combo from a given source node.
    std::pair <ComboPair,unsigned int> cheapestForNode(std::vector<std::pair<ComboPair, unsigned int>> pCombos, std::pair<ComboPair, unsigned int> source, double load){
        int edge;
        unsigned int sourceCost;
        std::pair<ComboPair, unsigned int> out(pCombos[0].first, pCombos[0].second);
        Economic_Dispatch dispatch;
            sourceCost = source.first.getEconomicDispatch() + source.second;
            for (int i = 0; i < pCombos.size(); i++) {
                if (pCombos[i].first.getMaxPowerOut() >= load && pCombos[i].first.getMinPowerOut() <= load){
                    edge = getEdgeCost(pCombos[i].first.getCombo(), source.first.getCombo());
                    if (sourceCost + edge < out.second) {
                        out.second = edge + sourceCost;
                        out.first = pCombos[i].first;
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
        std::pair<ComboPair, unsigned int> cheapestPair = std::pair<ComboPair, unsigned int>(pairs.at(0).first, pairs.at(0).second);
        for (std::pair<ComboPair, unsigned int> pair : pairs) {
            if (pair.first.getMaxPowerOut() >= load && pair.first.getEconomicDispatch() < cheapestPair.first.getEconomicDispatch()) {
                cheapestPair = pair;
            }
        }
        return cheapestPair;
    }

    //Output a vector of pairs that consists of the generator combo path and the overall cost.
    std::vector<std::pair<ComboPair,unsigned int>> cheapestRoutes(std::vector<std::pair<ComboPair, unsigned int>> source, std::vector<std::pair<ComboPair, unsigned int>> next,double load){
        std::vector<std::pair<ComboPair,unsigned int>> out;
        for(int i =0; i < source.size(); i++){
            out.push_back(cheapestForNode(next,source[i],load));
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
            pair.second += source.second + getEdgeCost(source.first.getCombo(), pair.first.getCombo());
            newStates.push_back(pair);
        }
        return newStates;
    }
};


