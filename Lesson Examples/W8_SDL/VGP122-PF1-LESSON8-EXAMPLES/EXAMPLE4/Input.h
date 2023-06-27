#pragma once

#include "SDL.h"

class Input
{
	typedef void (*VisitFunction)();

public:
	static Input* getInstance();
	static void removeInstance();

	SDL_Event getInput();

	// Main game loop input event processing
	void handleEvents(VisitFunction);

private:
	// Default constructor and destructor
	Input() = default;
	~Input() = default;
	
	SDL_Event event;

	// Singleton 
	static Input* instance;
};