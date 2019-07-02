#pragma once

#include <SDL.h>
#include <vector>

class JN_SDLRenderer
{
public:
	JN_SDLRenderer(SDL_Window* win);
	~JN_SDLRenderer();

	void Render(std::vector<std::vector<bool>>);

private:
	SDL_Renderer* renderer = NULL;

};