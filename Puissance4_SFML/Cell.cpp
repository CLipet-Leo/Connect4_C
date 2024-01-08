#include "Cell.h"

Cell::Cell(float x, float y, const sf::Color& color, float width, float height)
    : GameObject(x, y, color, width, height), val(0), token(nullptr) 
{}

void Cell::setVal(int value) {
    val = value;
    if (token != nullptr) {
        token->setColorFromValue(val);
    }
}

void Cell::setToken(Token* newToken) {
    token = newToken;
}

Token* Cell::getToken() {
    return token;
}