#pragma once

class Window
{
public:
	SDL_Window* oWindow = NULL;
	SDL_Renderer* oRenderer = NULL;

	Window(int width, int height, bool* error);

	~Window();

	bool createRenderer();

	void update();
};
