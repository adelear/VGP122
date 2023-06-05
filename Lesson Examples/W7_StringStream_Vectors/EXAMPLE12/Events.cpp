#include "Events.h"

// Singleton initialization
Events* Events::getInstance()
{
	if (instance == nullptr)
		instance = new Events();

	return instance;
}

// Singleton deletion
void Events::removeInstance(Events*)
{
	delete instance;
}

SDL_Event Events::getEvent()
{
	return event;
}

// Main game loop input event processing
void Events::handleEvents(VisitFunction visitor)
{
	while (SDL_PollEvent(&event))
	{
		visitor();
	}
}

// Singleton initialization
Events* Events::instance = nullptr;