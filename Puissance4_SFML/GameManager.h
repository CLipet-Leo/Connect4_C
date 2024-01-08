#pragma once
#include <SFML/Graphics.hpp>

#include "Grid.h"

class GameManager
{
public:
	// D�finition des variables publiques
	int screenW, screenH;
	sf::RenderWindow* oWindow;
	sf::Event oEvent;

	// D�finition de constructeur et d�structeur
	GameManager(int screenW, int screenH);
	~GameManager();

	// D�finition des fonctions publiques
	void GameLoop();
	void detectEvent();
};

