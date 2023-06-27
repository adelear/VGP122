#pragma once

#include <cstdlib>
#include <ctime>

#include "SDL.h"
#include "SDL_Image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#include "Window.h"
#include "Input.h"

// Forward declaration - create Window first
class Window;

class Game
{
	// Renaming function pointer to VisitFunction
	typedef void (*VisitFunction)();

public:
	Game(std::string, int, int, int, int, bool = false);
	~Game();

	// Register visitor function pointers
	void acceptInput(VisitFunction);
	void acceptUpdate(VisitFunction);
	void acceptRender(VisitFunction);

	// Game states
	void start();
	void stop();
	void pause();
	void resume();

	void gameLoop();

	bool isRunning();
	bool isPaused();

	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();
	SDL_Event getInput();
	Uint32 getStartTime();
	Uint32 getDeltaTime();

private:
	// Main game loop processing
	void handleEvents();
	void update();
	void render();

	bool running;
	bool paused;

	// Initial game time and delta time
	Uint32 startTime = 0;
	Uint32 delta = 0;

	Window* window;
	Input* event;

	// User defined function pointers
	VisitFunction inputFunction;
	VisitFunction updateFunction;
	VisitFunction renderFunction;

	// Global frame rate
	static const float FPS;
	static const float DELAY_TIME;
};