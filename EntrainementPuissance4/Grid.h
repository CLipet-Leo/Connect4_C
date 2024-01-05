#pragma once

#include <iostream>
#include <vector>
#include "Cell.h"

class Grid
{
public:
	int rows, cols;
	std::vector<std::vector<Cell>> grid;

	Grid(int rows = 6, int cols = 7);
	~Grid();

	void draw();

private:

};

