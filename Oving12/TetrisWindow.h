#pragma once
#include "AnimationWindow.h"
#include "Color.h"
#include "Tetromino.h"
#include "widgets/Button.h"
#include "widgets/TextInput.h"
#include <map>

class TetrisWindow : public TDT4102::AnimationWindow {
  public:
    TetrisWindow(int width);
    void run();

  private:
    void handleInput();
    void generate_rand_tetromino();
    void draw_current_tetromino();
    void move_sideways(bool direction);
    void rotate(bool direction);
    void move_down();
    bool is_within_bounds(Tetromino &t);
    bool has_collided(Tetromino &t);
    void handle_collision(Tetromino &t);
    void draw_grid();
    void remove_full_rows();
    void fasten_tetromino(Tetromino &t);

    std::vector<std::vector<TetrominoType>> grid_matrix;
    Tetromino current_tetromino;
    int win_width;
    int win_height;
    int block_size;
    bool has_lost = false;

    const std::map<TetrominoType, TDT4102::Color> tetromino_color_map{
        {TetrominoType::I, TDT4102::Color::light_blue},
        {TetrominoType::J, TDT4102::Color::blue},
        {TetrominoType::L, TDT4102::Color::orange},
        {TetrominoType::S, TDT4102::Color::green},
        {TetrominoType::Z, TDT4102::Color::red},
        {TetrominoType::T, TDT4102::Color::purple},
        {TetrominoType::O, TDT4102::Color::yellow},
        {TetrominoType::NONE, TDT4102::Color::white},
    };
};
