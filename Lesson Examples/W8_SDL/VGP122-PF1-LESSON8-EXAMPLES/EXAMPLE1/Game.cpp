#include "Game.h"

// Initialize game
Game::Game(std::string title, int x, int y, int w, int h, bool flags)
{
	srand(static_cast<unsigned>(time(0)));

	window = Window::getInstance(title, x, y, w, h, flags);
	event = Input::getInstance();
}

// Shutdown game
Game::~Game()
{
	Input::removeInstance();
	Window::removeInstance();

	SDL_Quit();
}

// Regiter user defined event handler 
void Game::acceptInput(VisitFunction visitor)
{
	inputFunction = visitor;
}

// Regiter user defined update processing
void Game::acceptUpdate(VisitFunction visitor)
{
	updateFunction = visitor;
}

// Regiter user defined render processing
void Game::acceptRender(VisitFunction visitor)
{
	renderFunction = visitor;
}

// Update events
void Game::handleEvents()
{
	event->handleEvents(inputFunction);
}

// Update game logic
void Game::update()
{
	window->update(updateFunction);
}

// Render to screen
void Game::render()
{
	window->render(renderFunction);
}

// Start game and main game loop
void Game::start()
{
	running = true;
	paused = false;

	gameLoop();
}

// Stop main game loop
void Game::stop()
{
	running = false;
}

void Game::gameLoop()
{
	while (running)
	{
		startTime = SDL_GetTicks();

		handleEvents();
		update();
		render();

		delta = SDL_GetTicks() - startTime;

		if (delta < DELAY_TIME)
			SDL_Delay((DELAY_TIME - delta));
	}
}

// Pause main game loop
void Game::pause()
{
	paused = true;
}

// Resume game loop from pause
void Game::resume()
{
	paused = false;
}

bool Game::isRunning()
{
	return running;
}

bool Game::isPaused()
{
	return paused;
}

SDL_Window* Game::getWindow()
{
	return window->getWindow();
}

SDL_Renderer* Game::getRenderer()
{
	return window->renderer;
}

SDL_Event Game::getInput()
{
	return event->getEvent();
}

Uint32 Game::getStartTime()
{
	return startTime;
}

Uint32 Game::getDeltaTime()
{
	return delta;
}

// Set frame rate
const float Game::FPS = 60.0f;
const float Game::DELAY_TIME = 1000.0f / FPS;