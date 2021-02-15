#ifndef UNIT_COMMITMENT_PARSER_H
#define UNIT_COMMITMENT_PARSER_H

#include <string>
#include "matrix.h"

class Parser {
private:
    const std::string filepath;
    int row;
    int col;
    int getNumRows();
    int getNumCols();
public:
    explicit Parser(std::string path) : filepath(std::move(path)), row(getNumRows()), col(getNumCols()) {}
    void loadStringData(Matrix<std::string> &);
    void loadNumericData(Matrix<double> &);
    int getRow() const;
    int getCol() const;
};

#endif //UNIT_COMMITMENT_PARSER_H
