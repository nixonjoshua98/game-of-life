#include "JN_LifeGame.h"

#include <iostream>


JN_LifeGame::JN_LifeGame()
{
	CreateWorld();
}


JN_LifeGame::~JN_LifeGame()
{

}


void JN_LifeGame::Update()
{

	std::vector<std::vector<bool>> timeStepResults(WORLD_SIZE, std::vector<bool>(WORLD_SIZE));

	for (int i = 0; i < WORLD_SIZE; i++)
	{
		for (int j = 0; j < WORLD_SIZE; j++)
		{
			timeStepResults[i][j] = false;

			int neighbours = GetAliveNeighbours(i, j);

			// Alive with 2 or 3 neighbours
			if (worldVector[i][j] && (neighbours == 2 || neighbours == 3))
				timeStepResults[i][j] = true;

			// Dead with 3 neighbours
			else if (!worldVector[i][j] && neighbours == 3)
				timeStepResults[i][j] = true;
		}
	}

		// Copy time step into main array
		for (int i = 0; i < WORLD_SIZE; i++)
		{
			for (int j = 0; j < WORLD_SIZE; j++)
			{
				worldVector[i][j] = timeStepResults[i][j];
			}
		}
}


void JN_LifeGame::CreateWorld()
{
	worldVector.resize(WORLD_SIZE);

	// Set initial values
	for (int i = 0; i < WORLD_SIZE; i++)
	{
		for (int j = 0; j < WORLD_SIZE; j++)
		{
			worldVector[i].push_back(rand() % 2);
		}
	}

	//worldArray[3][2] = true;
	//worldArray[4][3] = true;
	//worldArray[4][4] = true;
	//worldArray[3][4] = true;
	//worldArray[2][4] = true;
	

}


int JN_LifeGame::GetAliveNeighbours(int y, int x)
{
	// y = UP/DOWN
	// x = LEFT/RIGHT

	int aliveNeighbours = 0;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			// i = UP/DOWN
			// j = LEFT/RIGHT

			int newY = y + i;
			int newX = x + j;

			// Ignore the square being queried
			if (i == 0 && j == 0)
				continue;


			if (newX >= 0 && newX < WORLD_SIZE && newY >= 0 && newY < WORLD_SIZE)
			{
				if (worldVector[newY][newX] == 1)
				{
					aliveNeighbours++;
				}
			}
		}
	}

	return aliveNeighbours;
}
