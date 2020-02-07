// Memory leak detection using NEW keyword instead of new
#ifdef _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#define NEW new( _NORMAL_BLOCK, __FILE__, __LINE__ )
	#include <stdlib.h>
	#include <crtdbg.h>
#else
	#define NEW new
#endif

// STD libraries
#include <iostream>
#include <math.h>

// Other libraries
#include "logger.h"
#include "timer.h"

void main()
{
	// Memory leak detection
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);

	Logger logger("Time (ms)");
	Timer loopTimer;

	for (int i = 0; i < 10000000; i++)
	{
		float a = std::sin(i);
	}

	logger.Log(std::to_string(loopTimer.Mark()), Logger::Type::Custom);

	int* a = NEW int[50];

	for (int i = 0; i < 10000000; i++)
	{
		float a = std::sin(i);
	}


	logger.Log(loopTimer.Mark());

	std::cin.get();

}