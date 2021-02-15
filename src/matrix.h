#ifndef UNIT_COMMITMENT_MATRIX_H
#define UNIT_COMMITMENT_MATRIX_H

#include <vector>

class Matrix {
private:
    const int row;
    const int col;
public:
    std::vector<double> data;
    Matrix(int mRows, int mCols) : row(mRows), col(mCols), data(mRows * mCols) { data.reserve(row * col);}
    int rows() const;
    int cols() const;
    double getValue(int, int);
    void setValue(int, int, double);
    void print();
};

#endif //UNIT_COMMITMENT_MATRIX_H
