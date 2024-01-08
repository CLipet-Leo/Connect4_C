#include "GameManager.h"

int main(int argc, char** argv)
{
    //Création d'une fenêtre
    GameManager game(420, 360);
    game.GameLoop();

    return 0;
}