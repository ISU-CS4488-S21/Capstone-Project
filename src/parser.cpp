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
Matrix<std::string> Parser::loadStringData() {
    Matrix<std::string> m = Matrix<std::string>(row, col);
    std::ifstream file(filepath);
    std::string line;

    while(std::getline(file, line)) {
        std::istringstream ss(line);

    }

    return m;
}

Matrix<double> Parser::loadNumericData() {
    Matrix<double> m = Matrix<double>(row, col);
    std::ifstream file(filepath);
    std::string line;

    while(std::getline(file, line)) {
        std::istringstream ss(line);

    }

    return m;
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

