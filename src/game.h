#pragma once

#include "pch.h"
// SDL, math, logger




class Game
{
	
public:
	enum class State 
	{
		InitializationFailed,
		NotInitialized,
		Initialized,
		Paused,
		Running,
		Quitting
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

	bool IsRunning();
	bool IsInitialized();
	State GetState();
	void SetState(State newState);

private:
	State state = State::NotInitialized;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Logger sdlLogger = Logger("SDL2 Game");
	Logger eventLogger = Logger("Event");
	Logger updateLogger = Logger("Update");

	// Test variable
	int count = 0;
};