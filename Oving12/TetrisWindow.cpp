#include "TetrisWindow.h"
#include <iostream>
#include <random>

TetrisWindow::TetrisWindow(int width)
    : win_width{width}, win_height{2 * win_width},
      block_size{Tetromino::blockSize},
      AnimationWindow{100, 100, width * Tetromino::blockSize,
                      2 * width * Tetromino::blockSize, "TETRIS"} {
    generate_rand_tetromino();
    // Init grid
    grid_matrix.resize(win_height);
    for (int i = 0; i < win_height; ++i) {
        grid_matrix.at(i).resize(win_width);
        for (int j = 0; j < win_width; ++j) {
            grid_matrix.at(i).at(j) = TetrominoType::NONE;
        }
    }
}

void TetrisWindow::run() {
    unsigned int framesSinceLastTetronimoMove = 0;
    const unsigned int framesPerTetronimoMove = 20;

    while (!should_close()) {
        draw_grid();
        framesSinceLastTetronimoMove++;
        if (framesSinceLastTetronimoMove >= framesPerTetronimoMove) {
            framesSinceLastTetronimoMove = 0;
            move_down();
        }
        handleInput();

        draw_current_tetromino();

        next_frame();
    }
}

void TetrisWindow::handleInput() {

    static bool lastZKeyState = false;
    static bool lastUpKeyState = false;
    static bool lastLeftKeyState = false;
    static bool lastRightKeyState = false;
    static bool lastDownKeyState = false;

    bool currentZKeyState = is_key_down(KeyboardKey::Z);
    bool currentUpKeyState = is_key_down(KeyboardKey::UP);
    bool currentLeftKeyState = is_key_down(KeyboardKey::LEFT);
    bool currentRightKeyState = is_key_down(KeyboardKey::RIGHT);
    bool currentDownKeyState = is_key_down(KeyboardKey::DOWN);

    if (currentZKeyState && !lastZKeyState) {
        rotate(false);
    }

    if (currentUpKeyState && !lastUpKeyState) {
        rotate(true);
    }

    if (currentLeftKeyState && !lastLeftKeyState) {
        move_sideways(false);
    }

    if (currentRightKeyState && !lastRightKeyState) {
        move_sideways(true);
    }

    if (currentDownKeyState && !lastDownKeyState) {
        move_down();
    }

    lastZKeyState = currentZKeyState;
    lastUpKeyState = currentUpKeyState;
    lastLeftKeyState = currentLeftKeyState;
    lastRightKeyState = currentRightKeyState;
    lastDownKeyState = currentDownKeyState;
}

void TetrisWindow::generate_rand_tetromino() {
    std::random_device seed;
    std::default_random_engine engine(seed());
    std::uniform_int_distribution<int> dist(0, 6);
    int rnd_int = dist(engine);
    TetrominoType t = static_cast<TetrominoType>(rnd_int);
    current_tetromino = Tetromino(TDT4102::Point{win_width / 2 - 1, 0}, t);
}

void TetrisWindow::move_sideways(bool direction) {
    TDT4102::Point &pos = current_tetromino.get_position();
    Tetromino t_copy = current_tetromino;
    if (direction) {
        pos.x += 1;
        if (!is_within_bounds(current_tetromino) ||
            has_collided(current_tetromino)) {
            pos.x -= 1;
        }
    } else {
        pos.x -= 1;
        if (!is_within_bounds(current_tetromino) ||
            has_collided(current_tetromino)) {
            pos.x += 1;
        }
    }
}

void TetrisWindow::rotate(bool direction) {
    if (direction) {
        current_tetromino.rotateCounterClockwise();
        if (!is_within_bounds(current_tetromino) ||
            has_collided(current_tetromino)) {
            current_tetromino.rotateClockwise();
        }
    } else {
        current_tetromino.rotateClockwise();
        if (!is_within_bounds(current_tetromino) ||
            has_collided(current_tetromino)) {
            current_tetromino.rotateCounterClockwise();
        }
    }
}

void TetrisWindow::move_down() {
    TDT4102::Point &pos = current_tetromino.get_position();
    pos.y += 1;
    if (has_collided(current_tetromino)) {
        pos.y -= 1;
        handle_collision(current_tetromino);
    }
}

bool TetrisWindow::is_within_bounds(Tetromino &t) const {
    int x = 0;
    int y = 0;
    TDT4102::Point pos = t.get_position();
    int size = t.get_matrix_size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (t.block_exists(i, j)) {
                x = pos.x + j;
                if (x < 0 || x >= win_width) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool TetrisWindow::has_collided(Tetromino &t) const {
    int x = 0;
    int y = 0;
    TDT4102::Point pos = t.get_position();
    int size = t.get_matrix_size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (t.block_exists(i, j)) {
                x = pos.x + j;
                y = pos.y + i;
                if (y >= win_height) {
                    return true;
                }
                if (grid_matrix.at(y).at(x) != TetrominoType::NONE) {
                    return true;
                }
            }
        }
    }
    return false;
}

void TetrisWindow::draw_current_tetromino() {
    for (int i = 0; i < current_tetromino.get_matrix_size(); ++i) {
        for (int j = 0; j < current_tetromino.get_matrix_size(); ++j) {
            if (current_tetromino.block_exists(i, j)) {
                TDT4102::Point pos = current_tetromino.get_position();
                int size = current_tetromino.blockSize;
                pos.x = pos.x * size + j * size;
                pos.y = pos.y * size + i * size;
                draw_rectangle(
                    pos, current_tetromino.blockSize,
                    current_tetromino.blockSize,
                    something_random_color_map.at(current_tetromino.tetType));
            }
        }
    }
}

void TetrisWindow::handle_collision(Tetromino &t) {}

void TetrisWindow::draw_grid() {
    int x = 0;
    int y = 0;
    for (int i = 0; i < win_height; ++i) {
        for (int j = 0; j < win_width; ++j) {
            x = j * block_size;
            y = i * block_size;
            draw_rectangle(TDT4102::Point{x, y}, block_size, block_size,
                           TDT4102::Color::white, TDT4102::Color::grey);
        }
    }
}