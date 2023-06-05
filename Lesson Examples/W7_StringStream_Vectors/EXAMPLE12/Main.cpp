#include <iostream>
#include <vector>
#include <string>

#include "SDL.h"

#include "Game.h"
#include "Window.h"
#include "Events.h"

// **********************************************
// Global Screen Resolution - change these values
// **********************************************
const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 640;

// *************************************
// Global Game Title - change this value
// *************************************
const std::string GAME_TITLE = "EXAMPLE";

// ****************************************************
// Global Initial Window Position - change these values
// ****************************************************
const int XPOS = SDL_WINDOWPOS_CENTERED;
const int YPOS = SDL_WINDOWPOS_CENTERED;

// Global game
Game* game;
int pause;

// ***************************************************
// Game Object Declaration - declare your objects here
// ***************************************************


// *************************
// Global Functions for Game
// *************************
void handleEvents();
void update();
void render();

int main(int argv, char** argc)
{
	game = new Game(GAME_TITLE, XPOS, YPOS, SCREEN_WIDTH, SCREEN_HEIGHT);

	pause = false;

	// ****************************************************
	// Game Object Instantiation - create your objects here
	// ****************************************************



	// Register game loop functions
	game->acceptEvent(handleEvents);
	game->acceptUpdate(update);
	game->acceptRender(render);
	
	// Start game if not paused
	if(!game->isPaused())
		game->start();

	// Quit game if not running and not paused
	if (!game->isRunning() && !game->isPaused())
		delete game;

	return 0;
}

// ***************************************************
// Game Event Handler Function - add input events here
// ***************************************************
void handleEvents()
{
	SDL_Event event = game->getEvent();

	switch (event.type)
	{
	case SDL_QUIT:
		game->stop();

		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_ESCAPE)
			game->stop();
		else if (event.key.keysym.sym == SDLK_p)
		{
			pause = !pause;

			if (pause)
				game->pause();
			else
				game->resume();
		}

		break;
	}
}

// ***************************************
// Game Update Function - add updates here
// ***************************************
void update()
{
	
}

// **********************************************
// Game Render Function - add render updates here
// **********************************************
void render()
{

}