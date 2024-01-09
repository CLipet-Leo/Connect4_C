#include <SDL.h>
#include <iostream>

#include "Window.h"

using namespace std;

Window::Window(int width, int height, bool* error)
{
    *error = false;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        *error = true;
        return;
    }

    //Create window
    oWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (oWindow == NULL)
    {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        *error = true;
        return;
    }
}

Window::~Window()
{
    SDL_DestroyRenderer(oRenderer);
    oRenderer = NULL;

    SDL_DestroyWindow(oWindow);
    oWindow = NULL;

    SDL_Quit();
}

bool Window::createRenderer()
{
    bool success = true;
    oRenderer = SDL_CreateRenderer(oWindow, -1, SDL_RENDERER_ACCELERATED);
    if (oRenderer == NULL)
    {
        cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
        return false;
    }

    SDL_SetRenderDrawColor(oRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    return success;
}

void Window::update()
{
    //Update screen
    SDL_RenderPresent(oRenderer);
}