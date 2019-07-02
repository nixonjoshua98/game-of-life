
// - My Files
#include "JN_LifeGame.h"
#include "JN_Window.h"
#include "JN_FPSLock.h"

// - Renderers
#include "JN_SDLRenderer.h"

// - 
#include <memory>
#include <iostream>
#include <SDL.h>


int main(int argc, char* argv[])
{
	srand((unsigned int)time(0));

	std::unique_ptr<JN_Window> window = std::make_unique<JN_Window>();
	std::unique_ptr<JN_LifeGame> lifeGame = std::make_unique<JN_LifeGame>();

	std::unique_ptr<JN_SDLRenderer> renderer = std::make_unique<JN_SDLRenderer>(window->window);

	bool running = true;
	int currentFPS = 0;
	SDL_Event event;

	while (running)
	{
		auto lock = JN_FPSLock(60, currentFPS);

		std::cout << "Ticks (FPS): " << currentFPS << std::endl;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;

			} // switch (event.type)

		} // while (SDL_PollEvent(&event))

		lifeGame->Update();	// Update() takes way too long - Knocks it down to 5 FPS

		renderer->Render(lifeGame->worldVector);

	} // while(running)

	SDL_Quit();

	return 0;
}