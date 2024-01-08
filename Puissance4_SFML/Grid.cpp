#include "Grid.h"

Grid::Grid(float startX, float startY, int rows, int cols, float cellSize) {
    // Dans le constructeur de Grid
    grid.resize(rows);
    for (int i = 0; i < rows; ++i) {
        grid[i].resize(cols, Cell(0.f, 0.f, sf::Color::White, cellSize, cellSize));
    }

    float x = startX;
    float y = startY;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j].SetPosition(x, y);
            x += cellSize;
        }
        x = startX;
        y += cellSize;
    }
}

void Grid::setCellValue(int row, int col, int value) {
    grid[row][col].setVal(value);
}

void Grid::draw(sf::RenderWindow& window) {
    for (auto& row : grid) {
        for (auto& cell : row) {
            cell.Draw(window);
        }
    }
}