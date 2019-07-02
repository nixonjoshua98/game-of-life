#include "JN_Window.h"

#include <iostream>

JN_Window::JN_Window()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(
			"Game of Life",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			500, 500,
			NULL
		);
	}
	else
	{
		SDL_Log("SDL did not init correctly: %s", SDL_GetError());
	}
}


JN_Window::~JN_Window()
{
	SDL_DestroyWindow(window);

	window = NULL;
}
