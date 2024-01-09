#pragma once

#include <vector>
#include "Cell.h"

using namespace std;

class Grid {
public:
    Grid(SDL_Renderer* renderer, int rows, int columns, int tileSize, int tileSpacing, std::map<int, SDL_Texture*>* map);

    void draw();

    void newFreeTile(int x, int y, int w, int h);

    Cell getFreeTile();

protected:
    SDL_Renderer* renderer;
    int rows;
    int columns;
    int tileSize;
    int tileSpacing;
    vector<vector<Tile>> grid;
    vector<Tile> freeTiles;
    int gridSize;
};