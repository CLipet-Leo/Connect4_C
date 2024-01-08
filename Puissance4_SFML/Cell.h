#pragma once

#include "GameObject.h"
#include "Token.h"

class Cell : public GameObject {
public:
    Cell(float x, float y, const sf::Color& color, float width, float height);
    void setVal(int value);
    void setToken(Token* newToken);
    Token* getToken();

private:
    int val;
    Token* token;

};