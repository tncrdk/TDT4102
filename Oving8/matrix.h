#pragma once
#include <iostream>
#include <utility>

namespace matrix {
class Matrix {
  private:
    int rows;
    int columns;
    double **ptr_arr;
    // Pointer to pointer
  public:
    Matrix(int rows, int columns) : rows(rows), columns(columns) {
        this->ptr_arr = new double *[rows];
        for (int i = 0; i < rows; ++i) {
            this->ptr_arr[i] = new double[columns];
            for (int j = 0; j < columns; ++j) {
                // *(*(ptr_arr + i) + j) = 0;
                this->ptr_arr[i][j] = 0;
            }
        }
    }
    explicit Matrix(int rows) : Matrix(rows, rows) {
        for (int i = 0; i < rows; ++i) {
            ptr_arr[i][i] = 1;
        }
    }
    Matrix(const Matrix &other) : Matrix(other.rows, other.columns) {
        for (int i = 0; i < other.rows; ++i) {
            for (int j = 0; j < other.columns; ++j) {
                this->ptr_arr[i][j] = other.get(i, j);
            }
        }
    };

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] ptr_arr[i];
        }
        delete[] ptr_arr;
    }

    double get(int row, int column) const;
    void set(int row, int column, double value);
    int get_rows() const { return rows; }
    int get_columns() const { return columns; };
    friend std::ostream &operator<<(std::ostream &os, const Matrix &obj);
    double *&operator[](int row) { return this->ptr_arr[row]; }
    Matrix &operator=(Matrix other);
    Matrix &operator+=(const Matrix &other);
    Matrix &operator+(Matrix other);
};
} // namespace matrix