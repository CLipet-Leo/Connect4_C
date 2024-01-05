#include "Game.h"

#include "Cell.h"

Game::Game(bool isRunning)
	: isRunning(isRunning)
{
	gridRows = 6;
	gridCols = 7;
	player = 1;
	playCol = 0;
}

Game::~Game()
{}

void Game::GameLoop()
{
	Grid grid(gridRows, gridCols);
	while (isRunning)
	{
		grid.draw();
		Play(&grid.grid, gridCols);
	}
	//grid.draw();
}

void Game::Play(std::vector<std::vector<Cell>>* grid, int maxCols)
{
	std::cout << "A ton tour joueur " << player << " !!!" << std::endl;
	std::cout << "Quelle colonne veut-tu jouer : ";
	std::cin >> playCol;
	// Vérification de colonne jouable
	while (playCol < 1 || playCol > maxCols || (*grid)[0][playCol-1].getVal() != " ")
	{
		std::cout << "La colonne que tu veux jouer est incorrect !" << std::endl;
		std::cout << "Quelle colonne veut-tu jouer : ";
		std::cin >> playCol;
	}
	// Adapte la colonne pour la grille
	playCol -= 1;
	// Regarde en dessous et place un pion
	checkUnder(grid, playCol);
}

void Game::checkUnder(std::vector<std::vector<Cell>>* grid, int playCol)
{
	// Défini le pion en fonction du joueur
	if (player == 1) {
		pion = "X";
	} else {
		pion = "O";
	}
	// Regarde en dessous et place un pion
	for (int row = 0; row < gridRows; row++)
	{
		if (row + 1 >= gridRows)
		{
			(*grid)[row][playCol].setVal(pion);
			break;
		}
		else if ((*grid)[row + 1][playCol].getVal() != " ")
		{
			(*grid)[row][playCol].setVal(pion);
			break;
		}
	}
	// Vérif du joueur
	if (player == 1) {
		player = 2;
	} else {
		player = 1;
	}
}