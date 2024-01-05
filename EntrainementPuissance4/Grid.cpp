#include "Grid.h"

Grid::Grid(int rows, int cols)
	: rows(rows), cols(cols)
{
	// Initialisez la grille de cellules
	grid.resize(rows, std::vector<Cell>(cols, Cell(0, 0, " ")));

	// Initialisation de la grille
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			grid[row][col] = Cell(col, row, " ");
		}
	}
}

Grid::~Grid()
{}

void Grid::draw()
{
	// On efface la console pour la remttre au propre
	system("cls");

	// Affichage de la grille
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			std::cout << "|" << grid[row][col].getVal();
		}
		std::cout << "|" << std::endl;
	}
	std::cout << std::endl;
}