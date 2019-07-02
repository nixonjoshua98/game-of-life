#include "JN_FPSLock.h"

#include <SDL.h>
#include <iostream>
#include <cmath>


JN_FPSLock::JN_FPSLock(int targetFPS, int& refFPS): returnFPS(refFPS)
{
	this->targetFPS = targetFPS;

	timeAtCreation = std::chrono::system_clock::now();
}


JN_FPSLock::~JN_FPSLock()
{
	float deltaTimeBeforeWait = CalculateDeltaTime();

	float targetDeltaTime = 1000.0f / targetFPS;

	SDL_Delay(std::fmax(targetDeltaTime - deltaTimeBeforeWait, 0));

	float deltaTimeAfterWait = CalculateDeltaTime();

	returnFPS = 1000.0f / deltaTimeAfterWait;
}

float JN_FPSLock::CalculateDeltaTime()
{
	auto now = std::chrono::system_clock::now();

	std::chrono::duration<float, std::milli> span = now - timeAtCreation;

	return span.count();
}
