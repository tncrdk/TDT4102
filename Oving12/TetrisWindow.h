#pragma once
#include "AnimationWindow.h"
// #include "Color.h"
#include "Tetromino.h"
#include "widgets/Button.h"
#include "widgets/TextInput.h"
// #include <map>

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
    bool is_within_bounds(Tetromino &t) const;
    bool has_collided(Tetromino &t) const;
    void handle_collision(Tetromino &t);
    void draw_grid();

    std::vector<std::vector<TetrominoType>> grid_matrix;
    Tetromino current_tetromino;
    int win_width;
    int win_height;
    int block_size;
};
