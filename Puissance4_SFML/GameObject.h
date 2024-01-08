#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	// Définition des variables publiques
	sf::RectangleShape* oRectangle = NULL;
	sf::CircleShape* oCircle = NULL; 
	sf::Shape* oShape = NULL;
	float x, y, width, height, radius;
	sf::Color color = sf::Color::Transparent; 
	sf::Vector2f oPosition = { 0.f, 0.f };
	sf::Vector2f oDirection = { 0.f, 0.f };

	// Définition de constructeur et déstructeur
	GameObject(float x, float y, const sf::Color& color, float r);
	GameObject(float x, float y, const sf::Color& color, float w, float h);
	~GameObject();

	// Définition des fonctions publiques
	void SetPosition(float fX = 0, float fY = 0, float fRatioX = 0.5f, float fRatioY = 0.5f);
	const sf::Vector2f& GetPosition(float fRatioX = 0.5f, float fRatioY = 0.5f);
	virtual void Draw(sf::RenderWindow& window);
	void Move(float dt);
};

