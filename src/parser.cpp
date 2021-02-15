#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "parser.h"

/**
 * Reads csv data into a Matrix of strings.
 *
 * @param &m: A reference to a stack allocated Matrix object.
 */
void Parser::loadStringData(Matrix<std::string> &m) {
    std::ifstream file(filepath);
    std::string line;

    for(int i = 0; i < row; ++i) {
        std::getline(file, line);
        line.pop_back();
        std::istringstream ss(line);
        std::string token;

        for(int j = 0; j < col; ++j) {
            std::getline(ss, token, ',');
            m.setValue(i, j, token);
        }
    }
}

/**
 * Reads csv data into a Matrix of doubles.
 *
 * @param &m: A reference to a stack allocated Matrix object.
 */
void Parser::loadNumericData(Matrix<double> &m) {
    std::ifstream file(filepath);
    std::string line;

    for(int i = 0; i < row; ++i) {
        std::getline(file, line);
        line.pop_back();
        std::istringstream ss(line);
        std::string token;

        for(int j = 0; j < col; ++j) {
            std::getline(ss, token, ',');
            m.setValue(i, j, std::stod(token));
        }
    }
}

/**
 * Calculates the number of rows in a .csv file.
 *
 * @return The number of lines contained in the file at filepath.
 */
int Parser::getNumRows() {
    std::ifstream file(filepath);
    file.unsetf(std::ios_base::skipws);
    return std::count(std::istream_iterator<char>(file), std::istream_iterator<char>(), '\n') + 1;
}

/**
 * Calculates the number of columns in a .csv file.
 *
 * @return The number of commas contained in the first line of the file at filepath.
 */
int Parser::getNumCols() {
    std::ifstream file(filepath);
    std::string line;
    std::getline(file, line);
    return std::count(line.begin(), line.end(), ',') + 1;
}

int Parser::getRow() const {
    return row;
}

int Parser::getCol() const {
    return col;
}

