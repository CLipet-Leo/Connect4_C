#include <iostream>
#include <random>

#include "Grid.h"

using namespace std;

Grid::Grid(SDL_Renderer* renderer, int rows, int columns, int tileSize, int tileSpacing, std::map<int, SDL_Texture*>* map)
	: renderer(renderer), rows(rows), columns(columns), tileSize(tileSize), tileSpacing(tileSpacing) {
	// Initialisez la grille de tuiles
	grid.resize(rows, std::vector<Tile>(columns, Tile(renderer, 0, 0, tileSize, tileSize, { 255, 255, 255, 255 }, 0, map)));

	// Calculez la largeur et la hauteur de l'espace entre les tuiles
	gridSize = rows;
	int spacingX = tileSpacing;
	int spacingY = tileSpacing;

	// Initialisation des valeurs des tuiles à zéro et avec un espacement
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < columns; col++) {
			int tileX = col * (tileSize + spacingX);
			int tileY = row * (tileSize + spacingY);
			grid[row][col] = Tile(renderer, tileX, tileY, tileSize, tileSize, { 204, 192, 179, 255 }, 0, map);
		}
	}
}

void Grid::draw()
{
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < columns; col++) {
			grid[row][col].draw();
		}
	}
}

//void Grid::spawnBlock(int usecase) {
//	switch (usecase)
//	{
//	case 0:
//	{
//		int row, col;
//		if (checkFreeTiles(row, col)) {
//			// Générez une nouvelle tuile (exemple : valeur aléatoire entre 2 et 4)
//			int value = 2 + (rand() % 2) * 2; // Génère 2 ou 4
//			grid[row][col].setValue(value);
//	
//		}
//		break;
//	}
//	case 1:
//	{
//		grid[0][1].setValue(1024);
//		grid[0][2].setValue(1024);
//		break;
//	}
//	}
//}
//
//bool Grid::checkFreeTiles(int& row, int& col) {
//	// Parcourez la grille pour trouver une tuile vide
//	for (row = 0; row < rows; row++) {
//		for (col = 0; col < columns; col++) {
//			if (grid[row][col].getValue() == 0) {
//				return true; // Une tuile vide a été trouvée
//			}
//		}
//	}
//	return false; // Aucune tuile vide trouvée
//}

bool Grid::checkFreeTiles()
{
	//int spacingX = tileSpacing;
	//int spacingY = tileSpacing;
	freeTiles.clear();
	int counter = 0;
	int i = 0, j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			if (grid[i][j].getValue() == 0)
			{
				newFreeTile(i, j, 0, 0);
				counter++;
			}
		}
	}
	if (counter == 0)
	{
		// returns true if the grid is full
		return true;
	}
	else
	{
		return false;
	}
}

void Grid::newFreeTile(int x, int y, int w, int h)
{
	this->freeTiles.push_back(Tile(renderer, x, y, w, h, { 204, 192, 179, 255 }, 0, NULL));
}

Tile Grid::getFreeTile()
{
	size_t range = this->freeTiles.size();
	if (range == 0)
	{
		return Tile(renderer, -1, -1, tileSize, tileSize, { 204, 192, 179, 255 }, 0, NULL);
	}
	int index = rand() % range;
	Tile newTile = this->freeTiles[index];
	this->freeTiles.erase(this->freeTiles.begin() + index);
	return newTile;
}