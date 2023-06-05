#pragma once

#include <iostream>
#include <string>

#include "SDL.h"

#include "Game.h"

class Window
{
	// Game object can access private members of Window
	friend class Game;

	// Renaming function pointer to VisitFunction
	typedef void (*VisitFunction)();

public:
	// Singleton method to return instance
	static Window* getInstance(std::string, int, int, int, int, bool = false);
	
	// Singleton destructor
	static void removeWindow(Window*);

	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();

private:
	Window(std::string, int, int, int, int, bool = false);
	~Window();

	// Main game loop update processing
	void update(VisitFunction);

	// Main game loop render processing to window
	void render(VisitFunction);

	int x;
	int y;
	int w;
	int h;

	std::string title;
	bool fullScreen;

	SDL_Window* window;
	SDL_Renderer* renderer;

	// Singleton
	static Window* instance;
};