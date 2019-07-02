#include "JN_SDLRenderer.h"



JN_SDLRenderer::JN_SDLRenderer(SDL_Window* win)
{
	renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);
}


JN_SDLRenderer::~JN_SDLRenderer()
{
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
}


void JN_SDLRenderer::Render(std::vector<std::vector<bool>> vec)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(renderer);

	// Render stuff here
	SDL_Rect rect = { 0, 0, 5, 5 };

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			if (vec[j][i])
			{
				SDL_SetRenderDrawColor(renderer, 0, 155, 0, 255);

				SDL_RenderDrawRect(renderer, &rect);
			}

			rect.x += 5;
		}

		rect.x = 0;
		rect.y += 5;
	}

	// ---

	SDL_RenderPresent(renderer);
}
