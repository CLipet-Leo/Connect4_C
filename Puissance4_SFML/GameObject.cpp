#include "GameObject.h"

GameObject::GameObject(float x, float y, const sf::Color& color, float r)
	:x(x), y(y), color(color), radius(r)
{
	oCircle = new sf::CircleShape;

	oCircle->setRadius(radius);
	oCircle->setFillColor(color);

	oShape = oCircle;

	SetPosition(x, y);
}

GameObject::GameObject(float x, float y, const sf::Color& color, float w, float h)
	:x(x), y(y), color(color), width(w), height(h)
{
	oRectangle = new sf::RectangleShape;
	oRectangle->setSize(sf::Vector2f(w, h));
	oRectangle->setFillColor(color);

	oShape = oRectangle;

	SetPosition(x, y);
}

GameObject::~GameObject()
{
	if (oShape != nullptr)
		delete oShape;
}

void GameObject::SetPosition(float fX, float fY, float fRatioX, float fRatioY)
{
	oShape->setPosition(fX, fY);
}

const sf::Vector2f& GameObject::GetPosition(float fRatioX, float fRatioY)
{
	sf::Vector2f oOrigin = oShape->getOrigin();
	sf::Vector2f oPosition = oShape->getPosition();

	oPosition.x -= oOrigin.x;
	oPosition.y -= oOrigin.y;

	oPosition.x += fRatioX * width;
	oPosition.y += fRatioY * height;

	return oPosition;
}

void GameObject::Draw(sf::RenderWindow& window)
{
	if (oShape != nullptr)
		window.draw(*oShape);
}

void GameObject::Move(float fDeltaTime)
{
	oPosition = GetPosition();
	oPosition.x += (oDirection.x * 100) * fDeltaTime;
	oPosition.y += (oDirection.y * 100) * fDeltaTime;
	//cout << "Nouvelle pos : " << oOriginVect.x << "," << oOriginVect.y << std::endl;
	SetPosition(oPosition.x, oPosition.y);
}