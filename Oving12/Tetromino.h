#pragma once
#include "Color.h"
#include "Point.h"
#include <map>
#include <vector>

enum class TetrominoType { J, L, T, S, Z, O, I, NONE };

const std::map<TetrominoType, TDT4102::Color> something_random_color_map{
    {TetrominoType::I, TDT4102::Color::light_blue},
    {TetrominoType::J, TDT4102::Color::blue},
    {TetrominoType::L, TDT4102::Color::orange},
    {TetrominoType::S, TDT4102::Color::green},
    {TetrominoType::Z, TDT4102::Color::red},
    {TetrominoType::T, TDT4102::Color::purple},
    {TetrominoType::O, TDT4102::Color::yellow},
    {TetrominoType::NONE, TDT4102::Color::white},
};

const std::map<TetrominoType, int> something_random_map{
    {TetrominoType::I, 10}, {TetrominoType::J, 4},    {TetrominoType::L, 4},
    {TetrominoType::S, 4},  {TetrominoType::Z, 4},    {TetrominoType::T, 4},
    {TetrominoType::O, 4},  {TetrominoType::NONE, 4},
};

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