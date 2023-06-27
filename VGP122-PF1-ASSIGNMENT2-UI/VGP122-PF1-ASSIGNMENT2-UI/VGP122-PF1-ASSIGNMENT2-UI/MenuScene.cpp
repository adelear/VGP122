#include "MenuScene.h"

MenuScene::MenuScene()
{
	bg = new Image(Game::getRenderer(), "images/bg.png", 0, 0);

	start = new Button("images/buttons.png", 0, 0, 247, 108, 1, 6);

	start->position.x = (SCREEN_WIDTH / 2) - (start->w / 2);
	start->position.y = (SCREEN_HEIGHT / 2) - (start->h / 2);
}

void MenuScene::update()
{
	Scene::update();

	if (start->isPressed())
	{
		start->onRelease();
		std::cout << "START" << std::endl;
		SceneManager::getInstance()->removeScene();
	}
}

void MenuScene::render()
{
	Scene::render();
}

bool MenuScene::onEnter()
{
	addGameObject(0, bg);
	addGameObject(1, start);

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

	if (mousePosition.x >= start->position.x &&
		mousePosition.x <= start->position.x + start->w &&
		mousePosition.y >= start->position.y &&
		mousePosition.y <= start->position.y + start->h)
		start->onPress();
}

void MenuScene::onMouseButtonUp(SDL_Event& e)
{ }

void MenuScene::onMouseMove(SDL_Event& e)
{ }