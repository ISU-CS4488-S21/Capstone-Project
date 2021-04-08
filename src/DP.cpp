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





};


class unknown{
    DynamicProgrammingAlgo dynamicProg;

public:
    ///Adds cheapest S+E to determine with current state
    ///Can be modified baseed on edges and sources data structures
    std::vector<std::vector<double>> SourcePlusEdge2D(std::vector<std::vector<double>> edges, std::vector<std::vector<double>> sources,std::vector<std::vector<int>> combStatesCosts){

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

    std::vector<double> GetCheapestColumn(std::vector<std::vector<double>> addedCosts2D) {
        std::vector<double> tempCosts;
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
    void DisplaySPlusE(std::vector<std::vector<double>> shitPut1, std::vector<std::vector<double>> shitput2, std::vector<std::vector<int>> shitput3){
        int citiesLength=shitPut1.size();
        for (int i = 0; i <citiesLength ; ++i) {
            std::cout<<std::endl;
            for (int j = 0; j <citiesLength ; ++j) {
                std::cout << SourcePlusEdge2D(shitPut1, shitput2, shitput3)[i][j] << ", ";
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
            else{
                eCost += g1[i].getShutDownCost();
            }
        }
    }
    return eCost;
}

// Gets the cheapest path to any generator combo from a given source node.
std::pair <std::vector<Generator>,int> cheapestForNode(std::vector<std::vector<Generator>> pCombos, ComboPair source){
    int edge,sourceCost;
    std::pair <std::vector<Generator>,int> out (pCombos[0],std::numeric_limits<int>::max());
    Economic_Dispatch dispatch;
    sourceCost = source.getLambda()[0];
    for(int i = 0; i < pCombos.size(); i++){
        edge = getEdgeCost(pCombos[i],source.getCombo());
        if(sourceCost + edge < out.second) {
            out.second = edge + sourceCost;
            out.first = pCombos[i];
        }
    }
    return out;
}

//Output a vector of pairs that consists of the generator combo path and the overall cost.
std::vector<std::pair <std::vector<Generator>,int>> cheapestRoutes(std::vector<ComboPair> source, std::vector<std::vector<Generator>> next){
    std::vector<std::pair <std::vector<Generator>,int>> out;
    for(int i =0; i < source.size(); i++){
        out.push_back(cheapestForNode(next,source[i]));
    }
    return out;
}

};

