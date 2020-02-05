#include <Windows.h>
#include <iostream>
#include <math.h>
#include "logger.h"
#include "timer.h"

void main()
{
	Logger logger("Time (ms)");
	Timer loopTimer;

	for (int i = 0; i < 10000000; i++)
	{
		float a = std::sin(i);
	}

	logger.Log(std::to_string(loopTimer.Mark()), Logger::Type::Custom);


	for (int i = 0; i < 10000000; i++)
	{
		float a = std::sin(i);
	}


	logger.Log(loopTimer.Mark());

	while (!GetAsyncKeyState(VK_SPACE))
	{
	}


}