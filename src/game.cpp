#include "game.h"


Game::Game()
{
	logger.Log("Initializing game window without parameters...");
	Init("Default Window",0,0,600,400,false);
}

Game::Game(const char* title, int xpos, int ypos, unsigned int width, unsigned int height, bool fullScreen)
{
	logger.Log("Initializing game window...");
	Init(title, xpos, ypos, width, height, fullScreen);
}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

}

void Game::Init(const char* title, int xpos, int ypos, unsigned int width, unsigned int height, bool fullScreen)
{
	Uint32 flags = 0;
	if (fullScreen) flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			logger.Log("Window has been created!");

			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer)
			{
				state = State::Initialized;
				logger.Log("Renderer has been created!");
				logger.Log("Initialization sucessful!");
			}
			else
			{
				state = State::InitializationFailed;
				logger.Log("Create renderer failed...");
			}
		}
		else
		{
			state = State::InitializationFailed;
			logger.Log("Create window failed...");
		}

	}
	else
	{
		state = State::InitializationFailed;
		logger.Log("Initialization failed...");
	}

}

void Game::HandleEvents()
{
}

void Game::Update()
{
}

void Game::Render()
{
	// Test
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
}

void Game::Clean()
{
}

bool Game::isRunning()
{
	return false;
}
