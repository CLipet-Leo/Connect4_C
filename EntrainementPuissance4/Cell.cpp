#include "Cell.h"

Cell::Cell(int x, int y, std::string val)
{
    this->x = x;
    this->y = y;
    this->val = val;
}

Cell::~Cell()
{}

std::string Cell::getVal()
{
    return this->val;
}

int Cell::getX()
{
    return this->x;
}

int Cell::getY()
{
    return this->y;
}

void Cell::setVal(std::string newValue)
{
    val = newValue;
}