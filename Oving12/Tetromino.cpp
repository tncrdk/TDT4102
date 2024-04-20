#include "Tetromino.h"
#include "Point.h"
#include <exception>
#include <iostream>
#include <map>

const std::map<TetrominoType, std::vector<std::vector<int>>> initialMatrixMap{

    {TetrominoType::J, {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}}},
    {TetrominoType::I,
     {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}}},
    {TetrominoType::L, {{1, 1, 1}, {1, 0, 0}, {0, 0, 0}}},
    {TetrominoType::O, {{1, 1}, {1, 1}}},
    {TetrominoType::S, {{0, 1, 1}, {1, 1, 0}, {0, 0, 0}}},
    {TetrominoType::Z, {{1, 1, 0}, {0, 1, 1}, {0, 0, 0}}},
    {TetrominoType::T, {{0, 1, 0}, {1, 1, 1}, {0, 0, 0}}},
};

Tetromino::Tetromino() : matrixSize{0}, topLeftCorner{TDT4102::Point{0, 0}} {}

Tetromino::Tetromino(TDT4102::Point startingPoint, TetrominoType tetType)
    : topLeftCorner{startingPoint},
      matrixSize{int(initialMatrixMap.at(tetType).size())}, tetType{tetType} {

    blockMatrix.resize(matrixSize);
    std::vector<std::vector<int>> m = initialMatrixMap.at(tetType);

    for (int i = 0; i < matrixSize; ++i) {
        blockMatrix.at(i).resize(matrixSize);
        for (int j = 0; j < matrixSize; ++j) {
            if (m.at(i).at(j) == 0) {
                blockMatrix.at(i).at(j) = TetrominoType::NONE;
            } else {
                blockMatrix.at(i).at(j) = tetType;
            }
        }
    }
}

void Tetromino::rotateCounterClockwise() {
    // Første rotasjon, med hensyn på diagonalen
    for (int row = 0; row < matrixSize; row++) {
        for (int column = 0; column < row; column++) {
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    // Andre rotasjon, med hensyn på den midtre raden
    for (int row = 0; row < matrixSize / 2; row++) {
        for (int column = 0; column < matrixSize; column++) {
            std::swap(blockMatrix[row][column],
                      blockMatrix[matrixSize - row - 1][column]);
        }
    }
}

void Tetromino::rotateClockwise() {
    // Første rotasjon, med hensyn på diagonalen
    for (int row = 0; row < matrixSize; row++) {
        for (int column = 0; column < row; column++) {
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    // Andre rotasjon, med hensyn på den midtre kolonnen
    for (int row = 0; row < matrixSize; row++) {
        for (int column = 0; column < matrixSize / 2; column++) {
            std::swap(blockMatrix[row][column],
                      blockMatrix[row][matrixSize - column - 1]);
        }
    }
}

void Tetromino::move_left() { topLeftCorner.x -= blockSize; }
void Tetromino::move_right() { topLeftCorner.x += blockSize; }
void Tetromino::move_down() { topLeftCorner.y += blockSize; }

int Tetromino::get_matrix_size() const { return blockMatrix.size(); }
TDT4102::Point &Tetromino::get_position() { return topLeftCorner; }

bool Tetromino::block_exists(int row, int column) const {
    if (blockMatrix.at(row).at(column) == TetrominoType::NONE) {
        return false;
    }
    return true;
}

TetrominoType Tetromino::get_block(int row, int column) const {
    return blockMatrix.at(row).at(column);
}
