#include <stdexcept>
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
        data[row_index * col + col_index] = element;
    } else {
        throw std::invalid_argument("Index out of bounds.");
    }
}

