#pragma once

#include <iostream>

#include "Grid.h"


class Game
{
public:

	Game(bool isRunning);
	~Game();

	void GameLoop();
	void Play(std::vector<std::vector<Cell>>* grid, int maxCols);
	void checkUnder(std::vector<std::vector<Cell>>* grid, int playCol);

private:
	bool isRunning;
	int gridRows, gridCols;
	int player;
	int playCol;
	std::string pion;
};

