#pragma once
#include "Color.h"
#include "Point.h"
#include <map>
#include <vector>

enum class TetrominoType { J, L, T, S, Z, O, I, NONE };

class Tetromino {
  public:
    static constexpr int blockSize{30};

    Tetromino(TDT4102::Point startingPoint, TetrominoType tetType);
    Tetromino();

    void rotateClockwise();
    void rotateCounterClockwise();
    void move_right();
    void move_left();
    void move_down();

    bool block_exists(int row, int column) const;
    TetrominoType get_block(int row, int column) const;
    int get_matrix_size() const;
    TDT4102::Point &get_position();

    TetrominoType tetType;

  private:
    int matrixSize;
    TDT4102::Point topLeftCorner;
    std::vector<std::vector<TetrominoType>> blockMatrix;
};