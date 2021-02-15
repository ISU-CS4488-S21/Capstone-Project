#include <stdexcept>
#include <iostream>
#include "matrix.h"

int Matrix::rows() const {
    return row;
}

int Matrix::cols() const {
    return col;
}

double Matrix::getValue(int row_index, int col_index) {
    if(row_index < rows() && col_index < cols()) {
        return data[row_index * col + col_index];
    } else {
        throw std::invalid_argument("Index out of bounds.");
    }
}

void Matrix::setValue(int row_index, int col_index, double element) {
    if(row_index < rows() && col_index < cols()) {
        data.at(row_index * col + col_index) = element;
    } else {
        throw std::invalid_argument("Index out of bounds.");
    }
}

void Matrix::print() {
    std::cout << "Matrix Data" << std::endl;
    for(int i = 0; i < rows(); i++) {
        for(int j = 0; j < cols(); j++) {
            std::cout << data[i * col + j] << "\t\t";
        }
        std::cout << std::endl;
    }
}

