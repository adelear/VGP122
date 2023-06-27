#include "PlayScene.h"

PlayScene::PlayScene()
{
	bg = new Image(Game::getRenderer(), "images/bg.png", 0, 0);
	charSelect = new Image(Game::getRenderer(), "images/characterSelect.png", 0, 0);
	cursor1 = new Cursor("player1", Game::getRenderer(), "images/cursor.png", 191, 216, 41, 70, 4, 1);
	cursor2 = new Cursor("player2", Game::getRenderer(), "images/cursor.png", 317, 223, 41, 70, 4, 1);
}

void PlayScene::update()
{
	Scene::update();
}

void PlayScene::render()
{
	Scene::render();
}

bool PlayScene::onEnter()
{
	charSelect->position.x = (SCREEN_WIDTH / 2) - (charSelect->w / 2);
	charSelect->position.y = SCREEN_HEIGHT - charSelect->h;

	cursor1->animate(0, 1, 8);
	cursor2->animate(2, 3, 8);

	addGameObject(0, bg);
	addGameObject(1, charSelect);
	addGameObject(2, cursor1);
	addGameObject(3, cursor2);

	return true;
}

bool PlayScene::onExit()
{
	return true;
}

void PlayScene::onKeyDown(SDL_Event& e)
{
	InputManager* inputManager = InputManager::getInstance();

	if (inputManager->isKeyDown(SDL_SCANCODE_Q))
		Game::getInstance()->stop();
	else if (inputManager->isKeyDown(SDL_SCANCODE_D))
		cursor1->moveRight();
	else if (inputManager->isKeyDown(SDL_SCANCODE_A))
		cursor1->moveLeft();
	else if (inputManager->isKeyDown(SDL_SCANCODE_RIGHT))
		cursor2->moveRight();
	else if (inputManager->isKeyDown(SDL_SCANCODE_LEFT))
		cursor2->moveLeft();
	else if (inputManager->isKeyDown(SDL_SCANCODE_P))
	{
		if(!Game::getInstance()->isPaused())
			Game::getInstance()->pause();
		else
			Game::getInstance()->resume();
	}
}

void PlayScene::onControllerButtonDown(SDL_Event& e)
{
	InputManager* inputManager = InputManager::getInstance();

	if (e.cdevice.which % 2 == 0)
	{
		if (inputManager->getControllerButtonStates(DPADRIGHT))
			cursor1->moveRight();
		else if (inputManager->getControllerButtonStates(DPADLEFT))
			cursor1->moveLeft();
		else if (inputManager->getControllerButtonStates(GUIDE))
			Game::getInstance()->stop();
	}
	else 
	{
		if (inputManager->getControllerButtonStates(DPADRIGHT))
			cursor2->moveRight();
		else if (inputManager->getControllerButtonStates(DPADLEFT))
			cursor2->moveLeft();
		else if (inputManager->getControllerButtonStates(GUIDE))
			Game::getInstance()->stop();
	}
}

void PlayScene::onControllerAxisMotion(SDL_Event& e)
{
	InputManager* inputManager = InputManager::getInstance();

	if (e.cdevice.which % 2 == 0)
	{
		if ((inputManager->getControllerAxisStates(LEFTX) || inputManager->getControllerAxisStates(RIGHTX)) && e.caxis.value == 32767)
			cursor1->moveRight();
		else if ((inputManager->getControllerAxisStates(LEFTX) || inputManager->getControllerAxisStates(RIGHTX)) && e.caxis.value == -32768)
			cursor1->moveLeft();
	}
	else
	{
		if ((inputManager->getControllerAxisStates(LEFTX) || inputManager->getControllerAxisStates(RIGHTX)) && e.caxis.value == 32767)
			cursor2->moveRight();
		else if ((inputManager->getControllerAxisStates(LEFTX) || inputManager->getControllerAxisStates(RIGHTX)) && e.caxis.value == -32768)
			cursor2->moveLeft();
	}
}