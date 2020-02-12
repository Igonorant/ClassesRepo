#pragma once

#include "SDL.h"
#include "logger.h"


class Game
{
	
public:
	enum class State 
	{
		InitializationFailed,
		NotInitialized,
		Initialized,
		Paused,
		Running
	};

public:
	Game();
	Game(const char* title, int xpos, int ypos, unsigned int width, unsigned int height, bool fullScreen);
	~Game();

	void Init(const char* title,int xpos, int ypos, unsigned int width, unsigned int height, bool fullScreen);

	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool isRunning();

private:
	State state = State::NotInitialized;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Logger logger = Logger::Logger("SDL2 Game");

};