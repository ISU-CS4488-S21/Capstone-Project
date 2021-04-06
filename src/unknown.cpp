//
// Created by Deepson Khadka on 4/4/21.
//
#include <vector>
#include <iostream>


///Adds cheapest S+E to determine current
///Compares all possible source and edges
class unknown{
public:
    std::vector<std::vector<int>> SourcePlusEdge2D(std::vector<std::vector<int>> edges, std::vector<std::vector<int>> sources,std::vector<std::vector<int>> combStatesCosts){
        for (int i = 0; i <edges.at(0).size() ; ++i) {
            for (int j = 0; j <edges.at(1).size(); ++j) {
                combStatesCosts[i][j]=(edges[i][j]+sources[i][j])*combStatesCosts[i][j];
            }
        }
        return combStatesCosts;
    }


    void DisplayShitArrays(std::vector<std::vector<int>> shitPut1, std::vector<std::vector<int>> shitput2,std::vector<std::vector<int>> shitput3){
        int citiesLength=shitPut1.size();
        for (int i = 0; i <citiesLength ; ++i) {
            std::cout<<std::endl;
            for (int j = 0; j <citiesLength ; ++j) {
                std::cout << SourcePlusEdge2D(shitPut1, shitput2, shitput3)[i][j] << ", ";
            }
            std::cout<<std::endl;
        }
    }

};

