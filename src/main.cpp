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

	// Create main game object
	Game game("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);
	
	// Check if initialization was successful
	if (game.IsInitialized())
	{
		game.SetState(Game::State::Running);
	}
	else
	{
		std::cout << "Game object initialization failed!" << std::endl;
	}

	// Game loop
	while (game.IsRunning()) {

		game.HandleEvents();

		game.Update();

		game.Render();

	}

	game.Clean();

	return 0;
}