#include "PlayScene.h"

PlayScene::PlayScene()
{
	bg = game->createImage("bg", "images/bg.png", 0, 0);

	ground = new Wall("ground", 0, 216, SCREEN_WIDTH, SCREEN_HEIGHT - 216);
	leftWall = new Wall("left", -2, 0, 2, SCREEN_HEIGHT);
	rightWall = new Wall("right", SCREEN_WIDTH + 2, 0, 2, SCREEN_HEIGHT);
	ken = new Character("ken", "images/ken.png", 100, 125, 43, 91, 4, 4);
}

void PlayScene::update()
{
	Scene::update();

	Collider leftCollider = leftWall->getCollider();
	Collider rightCollider = rightWall->getCollider();
	Collider groundCollider = ground->getCollider();

	if (ken->checkCollision(leftCollider))
	{
		ken->leftHit();
	}
	
	if (ken->checkCollision(rightCollider))
	{
		ken->rightHit();
	}

	if (ken->checkCollision(groundCollider))
	{
		ken->groundHit();
	}
}

void PlayScene::render()
{
	Scene::render();
}

bool PlayScene::onEnter()
{
	addGameObject(bg, 0);
	addGameObject(ground, 0);
	addGameObject(leftWall, 0);
	addGameObject(rightWall, 0);
	addGameObject(ken, 1);

	ken->play("idle", 8, true, false, false);

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
		game->stop();
	else if (inputManager->isKeyDown(SDL_SCANCODE_D))
	{ 
		ken->rightPress();
		ken->move();
	}
	else if (inputManager->isKeyDown(SDL_SCANCODE_A))
	{ 
		ken->leftPress();
		ken->move();
	}
	else if (inputManager->isKeyDown(SDL_SCANCODE_W))
	{ 
		if (!ken->isJumping())
		{
			ken->upPress();
			ken->move();
		}
	}
	else if (inputManager->isKeyDown(SDL_SCANCODE_S))
	{ 
		ken->downPress();
		ken->move();
	}
	else if (inputManager->isKeyDown(SDL_SCANCODE_RETURN))
	{ }
	else if (inputManager->isKeyDown(SDL_SCANCODE_P))
	{
		if(!game->isPaused())
			game->pause();
		else
			game->resume();
	}
}

void PlayScene::onKeyUp(SDL_Event& e)
{
	InputManager* inputManager = InputManager::getInstance();

	if (inputManager->isKeyUp(e, SDL_SCANCODE_D))
	{
		ken->rightRelease();
		
		if(ken->isMoving())
			ken->stop();
	}
	else if (inputManager->isKeyUp(e, SDL_SCANCODE_A))
	{
		ken->leftRelease();

		if (ken->isMoving())
			ken->stop();
	}
	else if (inputManager->isKeyUp(e, SDL_SCANCODE_W))
	{
		ken->upRelease();
	}
	else if (inputManager->isKeyUp(e, SDL_SCANCODE_S))
	{
		ken->downRelease();
		
		if (ken->isMoving())
			ken->stop();
	}
	else if (inputManager->isKeyUp(e, SDL_SCANCODE_RETURN))
	{
	}
	else if (inputManager->isKeyUp(e, SDL_SCANCODE_P))
	{
		if (!game->isPaused())
			game->pause();
		else
			game->resume();
	}
}

Game* PlayScene::game = Game::getInstance();