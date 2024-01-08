#pragma once
#include <SFML/Graphics.hpp>

#include "Grid.h"

class GameManager
{
public:
	// Définition des variables publiques
	int screenW, screenH;
	sf::RenderWindow* oWindow;
	sf::Event oEvent;

	// Définition de constructeur et déstructeur
	GameManager(int screenW, int screenH);
	~GameManager();

	// Définition des fonctions publiques
	void GameLoop();
	void detectEvent();
};

