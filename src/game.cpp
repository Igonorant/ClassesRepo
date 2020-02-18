#include <pch.h>
#include "game.h"


Game::Game()
{
	sdlLogger.Log("Initializing game window without parameters...");
	Init("Default Window",0,0,600,400,false);
}

Game::Game(const char* title, int xpos, int ypos, unsigned int width, unsigned int height, bool fullScreen)
{
	sdlLogger.Log("Initializing game window...");
	Init(title, xpos, ypos, width, height, fullScreen);
}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	sdlLogger.Log("Game object destroyed successful!");
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
			sdlLogger.Log("Window has been created!");

			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				state = State::Initialized;
				sdlLogger.Log("Renderer has been created!");
				sdlLogger.Log("Initialization sucessful!");
			}
			else
			{
				state = State::InitializationFailed;
				sdlLogger.Log("Create renderer failed...");
			}
		}
		else
		{
			state = State::InitializationFailed;
			sdlLogger.Log("Create window failed...");
		}

	}
	else
	{
		state = State::InitializationFailed;
		sdlLogger.Log("Initialization failed...");
	}


	// SDL2 Image test
	SDL_Surface* tmpSurface = IMG_Load("assets/test/test_icon_32x32.png");
	testTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	//SDL_FreeSurface(tmpSurface);
}

void Game::HandleEvents()
{
	SDL_Event eventsQueue;

	while (SDL_PollEvent(&eventsQueue))
	{
		switch (eventsQueue.type) {
		case SDL_MOUSEMOTION:
			eventLogger.Log("We got a motion event.");
			break;
		case SDL_QUIT:
			SetState(State::Quitting);
			eventLogger.Log("We got a quitting event.");
			break;
		default:
			eventLogger.Log("Unhandled Event!");
			break;
		}
	}
}

void Game::Update()
{
	count++;
	if( count % 1000 == 0)
		updateLogger.Log(count);
	
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	
	// Render stuff

	SDL_RenderCopy(renderer, testTexture,NULL,NULL);


	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
}

bool Game::IsRunning()
{
	return state == State::Running;
}

bool Game::IsInitialized()
{
	return state == State::Initialized;
}

Game::State Game::GetState()
{
	return state;
}

void Game::SetState(State newState)
{
	state = newState;
}
