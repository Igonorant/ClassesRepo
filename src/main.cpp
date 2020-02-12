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
#include "game.h"
#include "logger.h"
#include "timer.h"

//#undef main

int main(int argc, char* argv[])
{
	// Memory leak detection
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);

	// Game loop
	Game game("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);
	game.Render();

	return 0;
}