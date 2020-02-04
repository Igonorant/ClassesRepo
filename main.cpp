#include <Windows.h>
#include <iostream>
#include "logger.h"
#include "timer.h"

void main()
{
	Logger logger("Time");
	Timer loopTimer;

	for (int i = 0; i < 20000000; i++)
	{
		int a = 5;
		a = a * a;
	}

	unsigned int processTime = loopTimer.Mark();

	std::cout << "The process time was: " << processTime << " ms." << std::endl;

	for (int i = 0; i < 20000000; i++)
	{
		int a = 5;
		a = a * a;
	}

	std::cout << "The process time was: " << processTime << " ms." << std::endl;

	while (!GetAsyncKeyState(VK_SPACE))
	{
	}


}