// Working for hard coded generators, need to implement with generator class.
// Also needs to be optimized for more generators. Takes too long after 7.
#include <Generator.h>

#include <limits>
#include <utility>
#include <vector>

// A function to find the minimized cost between a set of generators at
// every possible load.
double lambdaFunc(int load, const std::vector<Generator>& generators, int index){
    std::vector<std::pair<double,double>> gen;
    gen.reserve(generators.size());
    for(auto elem : generators){
        gen.push_back(std::make_pair<double, double>(elem.getB(), elem.getC()));
    }
    int maxLoad = load;
    double temp;
    double min = std::numeric_limits<int>::max();
    double g2;
    double g1;
    if(index <= 1){
        //The final branch of the generator tree to return optimized cost.
        while(load > 0){
            g1 = gen[0].first + gen[0].second*load*2;
            g2 = gen[1].first + gen[1].second*(maxLoad-load)*2;
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
            g2 = lambdaFunc(maxLoad - load,generators,index-1);
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
