#pragma once

#include "Grid.h"

class GameManager
{
public:
	// D�finition de constructeur et d�structeur
	GameManager();
	~GameManager();

	// D�finition des fonctions publiques
	void GameLoop();
	void detectEvent(bool running);
};