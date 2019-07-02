#pragma once

#include <SDL.h>

class JN_Window
{
public:
	JN_Window();
	~JN_Window();

	SDL_Window* window = NULL;
};