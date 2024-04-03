#include "MinesweeperWindow.h"
#include "widgets/TextInput.h"
#include <iostream>
#include <memory>
#include <random>

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height,
                                     int mines, const string &title)
    : // Initialiser medlemsvariabler, bruker konstruktoren til
      // AnimationWindow-klassen
      AnimationWindow{x, y, width * cellSize, (height + 5) * cellSize, title},
      width{width}, height{height}, mines{mines} {

    msg.setVisible(false);
    quit.setVisible(false);
    restart.setVisible(false);
    add(msg);
    add(mines_remaining);

    add(quit);
    add(restart);
    quit.setCallback(std::bind(&MinesweeperWindow::cb_quit, this));
    restart.setCallback(std::bind(&MinesweeperWindow::cb_restart, this));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            tiles.emplace_back(
                new Tile{Point{j * cellSize, i * cellSize}, cellSize});
            tiles.back()->setCallback(
                std::bind(&MinesweeperWindow::cb_click, this));
            auto temp = tiles.back().get();
            add(*temp);
        }
    }
    place_mines(mines);
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
    vector<Point> points;
    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            if (di == 0 && dj == 0) {
                continue;
            }

            Point neighbour{xy.x + di * cellSize, xy.y + dj * cellSize};
            if (inRange(neighbour)) {
                points.push_back(neighbour);
            }
        }
    }
    return points;
}

void MinesweeperWindow::openTile(Point xy) {
    if (is_done) {
        return;
    }

    std::shared_ptr<Tile> &tile = this->at(xy);
    Cell state = tile->getState();
    if (state == Cell::open || state == Cell::flagged) {
        return;
    }
    tile->open();
    if (tile->get_is_mine()) {
        loss_state();
        return;
    }
    std::vector<Point> adj_pts = this->adjacentPoints(xy);
    int mines = this->countMines(adj_pts);
    if (mines > 0) {
        tile->set_adjacent_mines(mines);
    } else {
        for (int i = 0; i < adj_pts.size(); ++i) {
            this->openTile(adj_pts.at(i));
        }
    }

    // Check if won
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Tile *tile = tiles.at(i * width + j).get();
            if (!tile->get_is_mine() && !(tile->getState() == Cell::open)) {
                return;
            }
        }
    }
    win_state();
}

void MinesweeperWindow::flagTile(Point xy) {
    if (is_done) {
        return;
    }
    this->at(xy)->flag();
    if (this->at(xy)->getState() == Cell::flagged) {
        flags++;
    } else {
        flags--;
    }

    mines_remaining.setText(
        to_string((mines - flags) > 0 ? (mines - flags) : 0));
}

// Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click() {

    Point xy{this->get_mouse_coordinates()};

    if (!inRange(xy)) {
        return;
    }
    if (this->is_left_mouse_button_down()) {
        openTile(xy);
    } else if (this->is_right_mouse_button_down()) {
        flagTile(xy);
    }
}

void MinesweeperWindow::cb_restart() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Tile *tile = tiles.at(i * width + j).get();
            tile->reset();
        }
    }
    is_done = false;
    flags = mines;
    mines_remaining.setText(to_string(flags));
    msg.setVisible(false);
    quit.setVisible(false);
    restart.setVisible(false);
    place_mines(mines);
}

void MinesweeperWindow::cb_quit() { this->close(); }

int MinesweeperWindow::countMines(vector<Point> coords) const {
    int mines = 0;
    for (int i = 0; i < coords.size(); ++i) {
        if (this->at(coords.at(i))->get_is_mine()) {
            ++mines;
        }
    }
    return mines;
}

void MinesweeperWindow::win_state() {
    this->msg.setVisible(true);
    this->msg.setText("YOU WON!");
    this->is_done = true;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Tile *tile = tiles.at(i * width + j).get();
            if (tile->get_is_mine() && !(tile->getState() == Cell::flagged)) {
                tile->flag();
            }
        }
    }
    quit.setVisible(true);
    restart.setVisible(true);
}

void MinesweeperWindow::loss_state() {
    msg.setText("YOU LOST!");
    this->msg.setVisible(true);
    this->is_done = true;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Tile *tile = tiles.at(i * width + j).get();
            tile->open();
        }
    }
    quit.setVisible(true);
    restart.setVisible(true);
}

void MinesweeperWindow::place_mines(int n) {
    // Legg til miner paa tilfeldige posisjoner
    std::random_device seed;
    std::default_random_engine engine(seed());
    std::uniform_int_distribution d(0, height * width - 1);
    int placed_mines = 0;
    while (placed_mines < mines) {
        int index = d(engine);
        if (tiles.at(index)->get_is_mine()) {
            continue;
        }
        tiles.at(index)->set_is_mine(true);
        placed_mines++;
    }
}