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

// SDL2 include
#include "SDL.h"
//#undef main

int main(int argc, char* argv[])
{
	// Memory leak detection
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);

	// SDL initialization
	SDL_Init(SDL_INIT_EVERYTHING);

	// SDL create window and renderer
	SDL_Window* window = SDL_CreateWindow("Main", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	// Test
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);

	return 0;
}