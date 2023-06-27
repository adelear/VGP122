#include <iostream>
#include <vector>
#include <string>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#include "Game.h"
#include "Window.h"
#include "Input.h"
#include "Image.h"
#include "Cursor.h"

// **********************************************
// Global Screen Resolution - change these values
// **********************************************
const int SCREEN_WIDTH = 550;
const int SCREEN_HEIGHT = 415;

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
Image* bg;
Image* charSelect;
Cursor* cursor1;
Cursor* cursor2;

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
	
	bg = new Image(game->getRenderer(), "images/bg.png", 0, 0);
	charSelect = new Image(game->getRenderer(), "images/characterSelect.png", 0, 0);
	cursor1 = new Cursor("player1", game->getRenderer(), "images/cursor.png", 191, 216, 41, 70, 4, 1);
	cursor2 = new Cursor("player2", game->getRenderer(), "images/cursor.png", 317, 223, 41, 70, 4, 1);

	charSelect->position.x = (SCREEN_WIDTH / 2) - (charSelect->w / 2);
	charSelect->position.y = SCREEN_HEIGHT - charSelect->h;

	cursor1->animate(0, 1, 8);
	cursor2->animate(2, 3, 8);

	ResourceManager::getInstance()->addGameObject(0, bg);
	ResourceManager::getInstance()->addGameObject(1, charSelect);
	ResourceManager::getInstance()->addGameObject(2, cursor1);
	ResourceManager::getInstance()->addGameObject(3, cursor2);

	// Register game loop functions
	game->acceptInput(handleEvents);
	game->acceptUpdate(update);
	game->acceptRender(render);
	
	// Start game if not paused
	if(!game->isPaused())
		game->start();

	// Quit game if not running and not paused
	if (!game->isRunning() && !game->isPaused())
	{
		std::map<int, Object*>::iterator it = ResourceManager::gameObjects.begin();
		
		while (it != ResourceManager::gameObjects.end())
		{			
			delete (*it).second;

			++it;
		}
		
		ResourceManager::removeInstance(ResourceManager::getInstance());

		delete game;
	}

	return 0;
}

// ***************************************************
// Game Event Handler Function - add input events here
// ***************************************************
void handleEvents()
{
	SDL_Event event = game->getInput();

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
		else if (event.key.keysym.sym == SDLK_d)
			cursor1->moveRight();
		else if (event.key.keysym.sym == SDLK_a)
			cursor1->moveLeft();
		else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			cursor2->moveRight();
		else if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
			cursor2->moveLeft();

		break;
	}
}

// ***************************************
// Game Update Function - add updates here
// ***************************************
void update()
{
	std::map<int, Object*>::iterator it = ResourceManager::gameObjects.begin();

	while (it != ResourceManager::gameObjects.end())
	{
		(*it).second->update();

		++it;
	}
}

// **********************************************
// Game Render Function - add render updates here
// **********************************************
void render()
{
	std::map<int, Object*>::iterator it = ResourceManager::gameObjects.begin();

	while (it != ResourceManager::gameObjects.end())
	{
		(*it).second->render();

		++it;
	}
}