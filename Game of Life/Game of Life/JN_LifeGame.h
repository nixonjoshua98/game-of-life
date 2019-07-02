#pragma once

#include <memory>
#include <vector>

#include "JN_Constants.h"


class JN_LifeGame
{
public:
	JN_LifeGame();
	~JN_LifeGame();

	std::vector<std::vector<bool>> worldVector;

	void Update();

private:
	void CreateWorld();

	int GetAliveNeighbours(int, int);
};