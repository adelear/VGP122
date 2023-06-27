#include "Input.h"

// Singleton initialization
Input* Input::getInstance()
{
	if (instance == nullptr)
		instance = new Input();

	return instance;
}

// Singleton deletion
void Input::removeInstance()
{
	if(instance != nullptr)
		delete instance;
}

SDL_Event Input::getEvent()
{
	return event;
}

// Main game loop input event processing
void Input::handleEvents(VisitFunction visitor)
{
	while (SDL_PollEvent(&event))
	{
		visitor();
	}
}

// Singleton initialization
Input* Input::instance = nullptr;