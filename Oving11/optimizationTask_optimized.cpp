#include "Stopwatch.h"
#include <iostream>
#include <vector>

// Utdelt kode til oppgave 3

void setDiagonalValue_optimized(std::vector<std::vector<double>> &matrix,
                                double newValue) {
    // O(n)
    for (int index = 0; index < matrix.size(); index++) {
        matrix.at(index).at(index) = newValue;
    }
}

double sumMatrix_optimized(std::vector<std::vector<double>> &matrix) {
    double sum;
    // Cache friendly
    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < matrix.size(); col++) {
            double value = matrix.at(row).at(col);
            sum += value;
        }
    }
    return sum;
}

void optimizationTask_optimized() {

    const int matrixSize = 10000;

    // Create a matrix with zeros
    std::vector<std::vector<double>> matrix;
    matrix.resize(matrixSize);

    for (int i = 0; i < matrixSize; i++) {
        std::vector<double> column;
        matrix.at(i) = column;
        matrix.at(i).resize(matrixSize);
        for (int j = 0; j < matrixSize; j++) {
            matrix.at(i).at(j) = 0.0;
        }
    }

    // Set all elements on the diagonal to 0.41
    setDiagonalValue_optimized(matrix, 0.41);

    // Sum all elements in the matrix
    double total = sumMatrix_optimized(matrix);

    double coolerNumber = total + 2;
    std::cout << "TDT" << coolerNumber << std::endl;
}

// With arrays
template <std::size_t R, std::size_t C>
void setDiagonalValue_optimized_array(
    std::array<std::array<double, C>, R> *matrix, double newValue) {
    // O(n)
    for (int index = 0; index < matrix->size(); index++) {
        matrix->at(index).at(index) = newValue;
    }
}

template <std::size_t R, std::size_t C>
double sumMatrix_optimized_array(std::array<std::array<double, C>, R> *matrix) {
    double sum = 0;
    // Cache friendly
    for (int row = 0; row < matrix->size(); row++) {
        for (int col = 0; col < matrix->size(); col++) {
            sum += matrix->at(row).at(col);
        }
    }
    return sum;
}

void optimizationTask_optimized_array() {

    constexpr int matrixSize = 10000;

    // Create a matrix with zeros
    std::array<std::array<double, matrixSize>, matrixSize> *matrix =
        new std::array<std::array<double, matrixSize>, matrixSize>;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            matrix->at(i).at(j) = 0.0;
        }
    }

    // Set all elements on the diagonal to 0.41
    setDiagonalValue_optimized_array(matrix, 0.41);

    // Sum all elements in the matrix
    double total = sumMatrix_optimized_array(matrix);

    double coolerNumber = total + 2;
    std::cout << "TDT" << coolerNumber << std::endl;
}