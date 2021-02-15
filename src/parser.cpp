#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <iostream>
#include "parser.h"

/**
 * Loads in text from a csv file
 *
 * @param filepath: the path of the CSV file
 * @return a matrix containing the comma separate values of each line of the file in each row
 */
Matrix Parser::loadData() {
    /*
    std::ifstream inFile(filepath);
    std::string line;

    while (getline(inFile, line)) {     // read whole line of the file
        std::stringstream ss(line);

        while (getline(ss, data, ',')) {    // read string until a comma is hit
            //row.push_back(stod(data));
        }
        //if (!row.empty()) {
        //    M.push_back(row);
        //}
    }
     */
    std::cout << row << std::endl;
    std::cout << col << std::endl;
    return Matrix(2, 2);
}

int Parser::getNumRows() {
    std::ifstream file(filepath);
    file.unsetf(std::ios_base::skipws);
    return std::count(std::istream_iterator<char>(file), std::istream_iterator<char>(), '\n') + 1;
}

int Parser::getNumCols() {
    std::ifstream file(filepath);
    std::string line;
    std::getline(file, line);
    return std::count(line.begin(), line.end(), ',') + 1;
}
