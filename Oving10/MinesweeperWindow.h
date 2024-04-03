#pragma once
#include "AnimationWindow.h"
#include "Tile.h"
#include "widgets/TextInput.h"

using namespace std;
using namespace TDT4102;

// Minesweeper GUI
class MinesweeperWindow : public AnimationWindow {
  public:
    // storrelsen til hver tile
    static constexpr int cellSize = 30;
    MinesweeperWindow(int x, int y, int width, int height, int mines,
                      const string &title);

  private:
    const int width;  // Bredde i antall tiles
    const int height; // Hoyde i antall tiles
    const int mines;  // Antall miner
    bool is_done = false;
    int flags = 0;
    TextInput msg = TextInput(Point{0, Height()}, 140, cellSize, "");
    TextInput mines_remaining = TextInput(Point{0, Height() + cellSize}, 140,
                                          cellSize, std::to_string(mines));
    Button quit =
        Button(Point{0, Height() + 2 * cellSize}, 140, cellSize, "Quit");
    Button restart =
        Button(Point{0, Height() + 3 * cellSize}, 140, cellSize, "Restart");
    vector<shared_ptr<Tile>> tiles; // Vektor som inneholder alle tiles

    // hoyde og bredde i piksler
    int Height() const { return height * cellSize; }
    int Width() const { return width * cellSize; }

    // Returnerer en vektor med nabotilene rundt en tile, der hver tile
    // representeres som et punkt
    vector<Point> adjacentPoints(Point xy) const;

    // tell miner basert paa en liste tiles
    int countMines(vector<Point> coords) const;

    // Sjekker at et punkt er paa brettet
    bool inRange(Point xy) const {
        return xy.x >= 0 && xy.x < Width() && xy.y >= 0 && xy.y < Height();
    }

    // Returnerer en tile gitt et punkt
    shared_ptr<Tile> &at(Point xy) {
        return tiles[xy.x / cellSize + (xy.y / cellSize) * width];
    }
    const shared_ptr<Tile> &at(Point xy) const {
        return tiles[xy.x / cellSize + (xy.y / cellSize) * width];
    }

    // aapne og flagge rute
    void openTile(Point xy);
    void flagTile(Point xy);

    // win
    void win_state();
    void loss_state();

    // callback funksjoner til Tile knappene
    void cb_click();
    void cb_restart();
    void cb_quit();

    void place_mines(int n);
};
