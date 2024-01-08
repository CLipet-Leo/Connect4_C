#pragma once

#include <SFML/Graphics.hpp>
#include "Cell.h"

class Grid {
public:
    Grid(float startX, float startY, int rows, int cols, float cellSize);

    void setCellValue(int row, int col, int value);
    void draw(sf::RenderWindow& window);

private:
    std::vector<std::vector<Cell>> grid;
};