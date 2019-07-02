#pragma once

#include <chrono>


class JN_FPSLock
{
public:
	JN_FPSLock(int, int&);
	~JN_FPSLock();

private:
	std::chrono::system_clock::time_point timeAtCreation;

	int targetFPS;
	int& returnFPS;

	float CalculateDeltaTime();
};

