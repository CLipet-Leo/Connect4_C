#include "Token.h"

Token::Token(float x, float y, const sf::Color& color, float radius)
    : GameObject(x, y, color, radius) {}

void Token::setColorFromValue(int val) {
    sf::Color color = getColorFromValue(val); // Assure-toi d'implémenter cette fonction
    oShape->setFillColor(color);
}

sf::Color Token::getColorFromValue(int val)
{
    if (val == 0)
        return sf::Color::Transparent;
    else if (val == 1)
        return sf::Color::Blue;
    else
        return sf::Color::Red;
}