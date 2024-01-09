#pragma once

#include "Grid.h"

class GameManager
{
public:
	// Définition de constructeur et déstructeur
	GameManager();
	~GameManager();

	// Définition des fonctions publiques
	void GameLoop();
	void detectEvent(bool running);
};