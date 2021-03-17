// Working for hard coded generators, need to implement with generator class.
// Also needs to be optimized for more generators. Takes too long after 7.
#include <iostream>
#include <utility>
#include <vector>
#include <limits>
// A function to find the minimized cost between a set of generators at
// every possible load.
float lambdaFunc(int load,std::vector<std::pair<float,float>> gen,int index){
    int maxLoad = load;
    float temp;
    float min = std::numeric_limits<int>::max();
    float g2;
    float g1;
    if(index <= 1){
        //The final branch of the generator tree to return optimized cost.
        while(load > 0){
            g1 = gen[0].first + gen[0].second*load;
            g2 = gen[1].first + gen[1].second*(maxLoad-load);
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
            g1 = gen[index].first + gen[index].second*load*2;
            g2 = lambdaFunc(maxLoad - load,gen,index-1);
            temp = g1 + g2;
            if(min > temp){
                min = g1 + g2;
            }
            load -= 10;
        }
    }
    return min;
}
//   lambdaFunc(1000,generators,generators.size() - 1)
