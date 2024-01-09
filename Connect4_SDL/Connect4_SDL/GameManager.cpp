#include "Window.h"
#include <SDL.h>
#include <iostream>

#include "GameManager.h"

GameManager::GameManager()
{}

GameManager::~GameManager()
{}

void GameManager::GameLoop()
{
    srand(time(0));
    #define SCREEN_WIDTH 480
    #define SCREEN_HEIGHT 360

    bool error;

    Window window(SCREEN_WIDTH, SCREEN_HEIGHT, &error);
    window.createRenderer();
    if (error)
    {
        cout << "Failed to initialize!" << endl;
        exit(0);
    }
    
    bool running = true;

    while (running)
    {
        detectEvent(running);

        window.update();
    }
}

void GameManager::detectEvent(bool running)
{
    SDL_Event event;
    //Handle events on queue
    while (SDL_PollEvent(&event) != 0)
    {
        //User requests quit
        if (event.type == SDL_QUIT)
        {
            running = false;
        }
        //User presses a key
        if (event.type == SDL_KEYDOWN)
        {
            //Select surfaces based on key press
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                cout << "pressed up" << endl;
                break;

            case SDLK_DOWN:
                cout << "pressed down" << endl;
                break;

            case SDLK_LEFT:
                cout << "pressed left" << endl;
                break;

            case SDLK_RIGHT:
                cout << "pressed right" << endl;
                break;

            default:
                break;
            }
        }
    }
}