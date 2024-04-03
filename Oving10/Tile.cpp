#include "Tile.h"

// For aa sette Tilelabel i henhold til state
const std::map<Cell, std::string> cellToSymbol{
    {Cell::closed, ""}, {Cell::open, ""}, {Cell::flagged, "|>"}};

Tile::Tile(TDT4102::Point pos, int size)
    : Button({pos.x, pos.y}, 1.5 * size, size, "") {
    setButtonColor(TDT4102::Color::silver);
}

void Tile::open() {
    if (state == Cell::open || state == Cell::flagged) {
        return;
    }
    state = Cell::open;
    setButtonColor(TDT4102::Color::white);
    if (is_mine) {
        set_label("X");
        set_label_color(TDT4102::Color::red);
    }
}

void Tile::flag() {
    if (state == Cell::flagged) {
        state = Cell::closed;
        set_label(cellToSymbol.at(Cell::closed));
    } else if (state == Cell::closed) {
        state = Cell::flagged;
        set_label(cellToSymbol.at(Cell::flagged));
        set_label_color(TDT4102::Color::black);
    }
}

void Tile::set_adjacent_mines(int n) {
    if (n < 1 || n > 8) {
        return;
    }
    set_label(std::to_string(n));
    set_label_color(minesToColor.at(n));
}

void Tile::reset() {
    state = Cell::closed;
    is_mine = false;
    setButtonColor(TDT4102::Color::silver);
    set_label("");
}