#pragma once

#include "SDL.h"

class Events
{
	typedef void (*VisitFunction)();

public:
	static Events* getInstance();
	static void removeInstance(Events*);

	SDL_Event getEvent();

	// Main game loop input event processing
	void handleEvents(VisitFunction);

private:
	// Default constructor and destructor
	Events() = default;
	~Events() = default;
	
	SDL_Event event;

	// Singleton 
	static Events* instance;
};