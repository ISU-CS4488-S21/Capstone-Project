// Not quite working
#include <vector>
#include <iterator>
#include <iostream>

const int size = 3;

std::vector<std::vector<int>> genCombinations(std::array<int, size> comb, int i) {
    std::vector<std::vector<int>> total;
    if(i < size)
    {
        comb[i] = 0;
        std::vector<std::vector<int>> temp1 = genCombinations(comb, i + 1);

        total.insert(
                total.end(),
                std::make_move_iterator(temp1.begin()),
                std::make_move_iterator(temp1.end())
        );

        comb[i] = 1;
        std::vector<std::vector<int>> temp2 = genCombinations(comb, i + 1);

        total.insert(
                total.end(),
                std::make_move_iterator(temp2.begin()),
                std::make_move_iterator(temp2.end())
        );
    }

    return total;
}