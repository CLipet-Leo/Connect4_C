#pragma once
#include <string>

class Cell
{
public:
	Cell(int x, int y, std::string val);
	~Cell();

	std::string getVal();
	int getX();
	int getY();

	void setVal(std::string newValue);

private:
	int x, y;
	std::string val;

};

