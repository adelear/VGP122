#include "MenuScene.h"

MenuScene::MenuScene()
{
	bg = new Image(Game::getRenderer(), "images/bg.png", 0, 0);
	logo = new Image(Game::getRenderer(), "images/logo.png", (SCREEN_WIDTH / 2) - 923, 10);
	play = new Button("images/buttons.png", (SCREEN_WIDTH / 2) - 123, (SCREEN_HEIGHT / 2) - 54, 247, 108, 1, 6);

	play->setCurrentFrame(PLAY);
}

void MenuScene::update()
{
	Scene::update();
}

void MenuScene::render()
{
	Scene::render();
}

bool MenuScene::onEnter()
{
	addGameObject(0, bg);
	addGameObject(1, logo);
	addGameObject(2, play);

	return true;
}

bool MenuScene::onExit()
{
	return true;
}

void MenuScene::onKeyDown(SDL_Event& e)
{
	InputManager* inputManager = InputManager::getInstance();

	if (inputManager->isKeyDown(SDL_SCANCODE_Q))
		Game::getInstance()->stop();
	else if (inputManager->isKeyDown(SDL_SCANCODE_D))
		std::cout << "RIGHT" << std::endl;
	else if (inputManager->isKeyDown(SDL_SCANCODE_A))
		std::cout << "LEFT" << std::endl;
	else if (inputManager->isKeyDown(SDL_SCANCODE_P))
	{
		if (!Game::getInstance()->isPaused())
			Game::getInstance()->pause();
		else
			Game::getInstance()->resume();
	}
}

void MenuScene::onMouseButtonDown(SDL_Event& e)
{
	InputManager* inputManager = InputManager::getInstance(); 
	
	Vector2D mousePosition = inputManager->getMousePosition();

	if (mousePosition.x >= play->position.x && mousePosition.x <= play->position.x + play->w && mousePosition.y >= play->position.y && mousePosition.y <= play->position.y + play->h)
	{
		play->onPress();

		SceneManager::getInstance()->removeScene();
	}
}