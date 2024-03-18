#include "matrix.h"
#include <cassert>

namespace matrix {
std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.columns; ++j) {
            os << m.ptr_arr[i][j] << "  ";
        }
        os << "\n";
    }
    return os;
}
double Matrix::get(int row, int column) const {
    return this->ptr_arr[row][column];
}

void Matrix::set(int row, int column, double value) {
    this->ptr_arr[row][column] = value;
}

Matrix &Matrix::operator=(Matrix other) {
    this->rows = other.rows;
    this->columns = other.columns;
    std::swap(this->ptr_arr, other.ptr_arr);
    return *this;
}
Matrix &Matrix::operator+=(const Matrix &other) {
    assert((this->rows == other.rows) && (this->columns == other.columns));
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            this->ptr_arr[i][j] += other.ptr_arr[i][j];
        }
    }
    return *this;
}
Matrix &Matrix::operator+(Matrix other) {
    Matrix *result = new Matrix{*this};
    return *result += other;
}
} // namespace matrix
