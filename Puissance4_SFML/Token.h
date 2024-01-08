#pragma once
#include "GameObject.h"

class Token : public GameObject {
public:
	Token(float x, float y, const sf::Color& color, float radius);
	void setColorFromValue(int val);
	sf::Color getColorFromValue(int val);
};
