#include "GameManager.h"

GameManager::GameManager(int iWidth, int iHeight)
	: screenW(iWidth), screenH(iHeight)
{
	oWindow = new sf::RenderWindow(sf::VideoMode(screenW, screenH), "Connect_4");
	oWindow -> setFramerateLimit(30);
}

GameManager::~GameManager()
{
	delete oWindow;
}

void GameManager::GameLoop()
{
    sf::Clock deltaClock;
    float deltaTime = deltaClock.restart().asSeconds();

    // Création de la grille
    Grid grid(50.f, 50.f, 6, 7, 40.f); // Par exemple, une grille de 6 lignes par 7 colonnes avec des cases de taille 40x40

    // Modification de certaines valeurs pour tester
    grid.setCellValue(1, 2, 0.5f); // Par exemple, définir la valeur de la cellule en ligne 1, colonne 2 à 0.5

    while (oWindow->isOpen()) {
        // Events
        detectEvent();

        oWindow->clear(sf::Color::Black);

        // Dessiner la grille
        grid.draw(*oWindow);

        oWindow->display();
    }
}

void GameManager::detectEvent()
{
    // Event
    while (oWindow->pollEvent(oEvent)) {
        if (oEvent.type == sf::Event::Closed)
            oWindow->close();
    }
}