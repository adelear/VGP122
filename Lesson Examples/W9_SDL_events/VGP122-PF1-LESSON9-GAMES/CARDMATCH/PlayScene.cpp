#include "PlayScene.h"

PlayScene::PlayScene()
{
	currentCard = BLANK;

	bg = new Image(Game::getRenderer(), "images/bg.png", 0, 0);

	deck = new Deck();

	selector = new Selector("images/cards.png", deck->cards[currentCard]->position.x, deck->cards[currentCard]->position.y, 44, 64, 1, 12);

	pair = false;
	hand1 = nullptr;
	hand2 = nullptr;

	score = 0;
}

void PlayScene::update()
{
	Scene::update();

	selector->position = { deck->cards[currentCard]->position.x, selector->position.y = deck->cards[currentCard]->position.y };

	if (pair)
	{
		pair = false;

		hand1 = nullptr;
		hand2 = nullptr;

		++score;
	}

	if (score == NUMCARDS / 2)
	{
		std::cout << "YOU WIN" << std::endl;
		SceneManager::getInstance()->removeScene();
		Game::getInstance()->stop();
	}
}

void PlayScene::render()
{
	Scene::render();
}

bool PlayScene::onEnter()
{
	addGameObject(0, bg);
	addGameObject(1, deck);
	addGameObject(2, selector);

	return true;
}

bool PlayScene::onExit()
{
	std::cout << std::endl << std::endl << "Final Score: " << score << std::endl;
	return true;
}

void PlayScene::onKeyDown(SDL_Event& e)
{
	InputManager* inputManager = InputManager::getInstance();

	if (inputManager->isKeyDown(SDL_SCANCODE_Q))
		Game::getInstance()->stop();
	else if (inputManager->isKeyDown(SDL_SCANCODE_D))
		currentCard = (currentCard + 1) % NUMCARDS;
	else if (inputManager->isKeyDown(SDL_SCANCODE_A))
		currentCard = (--currentCard < 0) ? 17 : currentCard % NUMCARDS;
	else if (inputManager->isKeyDown(SDL_SCANCODE_W))
		currentCard = (currentCard - 6 < 0) ? NUMCARDS + (currentCard - 6) : (currentCard - 6) % NUMCARDS;
	else if (inputManager->isKeyDown(SDL_SCANCODE_S))
		currentCard = (currentCard + 6) % NUMCARDS;
	else if (inputManager->isKeyDown(SDL_SCANCODE_RETURN))
	{
		int face = deck->cards[currentCard]->getFace();
		deck->cards[currentCard]->setCurrentFrame(face);

		if (hand1 == nullptr)
			hand1 = deck->cards[currentCard];
		else if(hand1 != nullptr && hand2 == nullptr)
		{
			hand2 = deck->cards[currentCard];

			if (hand1->getFace() == hand2->getFace())
				pair = true;
			else
			{
				hand1->setCurrentFrame(BLANK);
				hand2->setCurrentFrame(BLANK);

				hand1 = nullptr;
				hand2 = nullptr;

				pair = false;
			}
		}
	}
	else if (inputManager->isKeyDown(SDL_SCANCODE_P))
	{
		if(!Game::getInstance()->isPaused())
			Game::getInstance()->pause();
		else
			Game::getInstance()->resume();
	}
}