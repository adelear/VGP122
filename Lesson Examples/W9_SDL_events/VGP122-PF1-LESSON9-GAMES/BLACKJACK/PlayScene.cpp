#include "PlayScene.h"

PlayScene::PlayScene()
{
	bg = new Image(Game::getRenderer(), "images/bg.png", 0, 0);
	hit = new Hit("images/buttons.png", 120, 100, 247, 108, 1, 6);
	stand = new Stand("images/buttons.png", 400, 100, 247, 108, 1, 6);
	pass = new Pass("images/buttons.png", 700, 100, 247, 108, 1, 6);
	ddown = new DDown("images/buttons.png", 1000, 100, 247, 108, 1, 6);
	split = new Split("images/buttons.png", 1300, 100, 247, 108, 1, 6);

	hit->setCurrentFrame(HIT);
	stand->setCurrentFrame(STAND);
	pass->setCurrentFrame(PASS);
	ddown->setCurrentFrame(DDOWN);
	split->setCurrentFrame(SPLIT);
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
	addGameObject(0, bg);
	addGameObject(1, hit);
	addGameObject(2, stand);
	addGameObject(3, pass);
	addGameObject(4, ddown);
	addGameObject(5, split);

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
		std::cout << "RIGHT" << std::endl;
	else if (inputManager->isKeyDown(SDL_SCANCODE_A))
		std::cout << "LEFT" << std::endl;
	else if (inputManager->isKeyDown(SDL_SCANCODE_P))
	{
		if(!Game::getInstance()->isPaused())
			Game::getInstance()->pause();
		else
			Game::getInstance()->resume();
	}
}

void PlayScene::onMouseButtonDown(SDL_Event& e)
{
	InputManager* inputManager = InputManager::getInstance();

	Vector2D mousePosition = inputManager->getMousePosition();

	if (mousePosition.x >= hit->position.x && 
		mousePosition.x <= hit->position.x + hit->w && 
		mousePosition.y >= hit->position.y && 
		mousePosition.y <= hit->position.y + hit->h)
	{
		std::cout << "HIT" << std::endl;
		hit->onPress();
	}
	else if (mousePosition.x >= stand->position.x &&
		mousePosition.x <= stand->position.x + stand->w &&
		mousePosition.y >= stand->position.y &&
		mousePosition.y <= stand->position.y + stand->h)
	{
		std::cout << "STAND" << std::endl;
		stand->onPress();
	}
	else if (mousePosition.x >= pass->position.x &&
		mousePosition.x <= pass->position.x + pass->w &&
		mousePosition.y >= pass->position.y &&
		mousePosition.y <= pass->position.y + pass->h)
	{
		std::cout << "PASS" << std::endl;
		pass->onPress();
	}
	else if (mousePosition.x >= ddown->position.x &&
		mousePosition.x <= ddown->position.x + ddown->w &&
		mousePosition.y >= ddown->position.y &&
		mousePosition.y <= ddown->position.y + ddown->h)
	{
		std::cout << "DOUBLE DOWN" << std::endl;
		ddown->onPress();
	}
	else if (mousePosition.x >= split->position.x &&
		mousePosition.x <= split->position.x + split->w &&
		mousePosition.y >= split->position.y &&
		mousePosition.y <= split->position.y + split->h)
	{
		std::cout << "SPLIT" << std::endl;
		split->onPress();
	}
}