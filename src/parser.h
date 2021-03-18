// Author: Andres Sewell
#ifndef UNIT_COMMITMENT_PARSER_H
#define UNIT_COMMITMENT_PARSER_H

#include <algorithm>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

template <class T>
class Parser {
private:
    const std::string filepath;
    int row;
    int col;
    int getNumRows() {
        std::ifstream file(filepath);
        file.unsetf(std::ios_base::skipws);
        return std::count(std::istream_iterator<char>(file), std::istream_iterator<char>(), '\n');
    }

    int getNumCols() {
        std::ifstream file(filepath);
        std::string line;
        std::getline(file, line);
        return std::count(line.begin(), line.end(), ',') + 1;
    }

public:
    explicit Parser(std::string path) : filepath(std::move(path)), row(getNumRows()), col(getNumCols()) {}

    std::vector<T> loadData() {
        std::vector<T> data;

        std::ifstream file(filepath);
        std::string line;

        if(row == 1) {
            std::getline(file, line);
            std::istringstream ss(line);
            std::string token;

            for(int i = 0; i < col; i++) {
                std::getline(ss, token, ',');
                std::stringstream convert(token);
                T value;
                convert >> value;
                data.push_back(value);
            }
        } else {
            // TODO: Fix Parser so that it can generate 2D vectors
            /*
            for(int i = 0; i < row; ++i) {
                std::getline(file, line);
                line.pop_back();
                std::istringstream ss(line);
                std::string token;

                for(int j = 0; j < col; ++j) {
                    std::getline(ss, token, ',');

                }
            }
             */
        }

        return data;
    }

    int getRow() const {
        return row;
    }

    int getCol() const {
        return col;
    }
};

#endif //UNIT_COMMITMENT_PARSER_H
