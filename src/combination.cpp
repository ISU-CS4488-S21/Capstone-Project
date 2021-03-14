// This file only exists as a space to get the concept working, and should be deleted later with it's code being moved
// to wherever it is needed.
#include <iostream>
#include <cmath>

// Algorithm citation: https://stackoverflow.com/questions/8374079/fastest-way-to-generate-all-binary-strings-of-size-n-into-a-boolean-array
void comboExample() {
    // Max size of 18 at this point because 2^18 is massive and is larger than the array size limit. Going higher is
    // maybe possible if we use std::vector or std::array instead, but forcing anything to have >2^18 rows might be
    // challenging no matter what.
    const int size = 18;
    unsigned int rows = std::pow(2, size);

    // This generates all combinations of k bit-strings. Each row i is a unique set of combinations
    bool combinations[rows][size];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < size; j++) {
            int val = rows * j + i;
            int ret = (1 & (val >> j));
            combinations[i][j] = ret != 0;
        }
    }

    // This is a rough example of how the combination array can be used to generate a second array using the combination
    // values. In order to not use tons of ram, probably we would want to create two sets of references per generator:
    // one in an off state and one in an on state and load our generatorlist with references rather than unique objects
    // in memory.
    char test[size];
    for(int i = 0; i < size; i++) {
        if(combinations[5][i] == 0) {
            test[i] = 'n';
        } else {
            test[i] = 'y';
        }
    }

    // Print out the test array just to see that the different characters are assigned based on the 0/1 combo values.
    for(char c : test) {
        std::cout << c << '\t';
    }
}