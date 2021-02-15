#ifndef UNIT_COMMITMENT_MATRIX_H
#define UNIT_COMMITMENT_MATRIX_H

#include <vector>
#include <stdexcept>
#include <iostream>

template <class T>
class Matrix {
private:
    const int row;
    const int col;
public:
    std::vector<T> data;
    Matrix(int mRows, int mCols) : row(mRows), col(mCols), data(mRows * mCols) { data.reserve(row * col);}
    int rows() const { return row; }
    int cols() const { return col; }

    T getValue(int row_index, int col_index) {
        if(row_index < rows() && col_index < cols()) {
            return data[row_index * col + col_index];
        } else {
            throw std::invalid_argument("Index out of bounds.");
        }
    };

    void setValue(int row_index, int col_index, T element) {
        if(row_index < rows() && col_index < cols()) {
            data.at(row_index * col + col_index) = element;
        } else {
            throw std::invalid_argument("Index out of bounds.");
        }
    }

    void print() {
        std::cout << "Matrix Data" << std::endl;
        for(int i = 0; i < rows(); i++) {
            for(int j = 0; j < cols(); j++) {
                std::cout << data[i * col + j] << "\t\t";
            }
            std::cout << std::endl;
        }
    }
};

#endif //UNIT_COMMITMENT_MATRIX_H
