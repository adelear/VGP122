#include "PlayScene.h"

PlayScene::PlayScene()
{
	currentCard = BLANK;

	bg = game->createImage("bg", "images/bg.png", 0, 0);

	deck = new Deck();

	selector = static_cast<Selector*>(game->createSprite("selector", "images/cards.png", 0, 0, 0, 0, 1, 12));

	selector->setCurrentFrame(SELECTOR);

	pair = false;
	hand1 = nullptr;
	hand2 = nullptr;

	score = 0;
}

void PlayScene::update()
{
	Scene::update();

	selector->setPosition(deck->cards[currentCard]->getPosition());

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
		game->stop();
	}
}

void PlayScene::render()
{
	Scene::render();
}

bool PlayScene::onEnter()
{
	addGameObject(bg, 0);
	addGameObject(deck, 1);
	addGameObject(selector, 2);

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
		game->stop();
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
		Card* selected = deck->cards[currentCard];
		
		if (!selected->isTurned())
		{
			int face = selected->getFace();
			std::string faceName = selected->getFaceName();
			selected->setCurrentFrame(face);
			selected->setTurned(true);

			if (hand1 == nullptr && hand2 == nullptr)
			{
				hand1 = selected;
				
				hand1->play(faceName, 14, false);
			}
			else if (hand1 != nullptr && hand1 != selected && hand2 == nullptr)
			{
				hand2 = selected;				

				if(hand1->getFace() == hand2->getFace())
				{
					hand1 = nullptr;
					hand2 = nullptr;

					pair = true;
				}
				else
				{
					hand2->play(faceName, 14, false);

					void* params = hand1;
					Game::getTimeManager()->addTimeout(&animationDelay, 1000, params, hand1->getGameObjectID());

					params = hand2;
					Game::getTimeManager()->addTimeout(&animationDelay, 1000, params, hand2->getGameObjectID());

					hand1->setTurned(false);
					hand2->setTurned(false);

					hand1 = nullptr;
					hand2 = nullptr;

					pair = false;
				}
			}
		}
	}
	else if (inputManager->isKeyDown(SDL_SCANCODE_P))
	{
		if(!game->isPaused())
			game->pause();
		else
			game->resume();
	}
}

Uint32 PlayScene::animationDelay(Uint32 delay, void* params)
{
	Card* c = static_cast<Card*>(params);

	c->play(c->getFaceName(), 14, false, true);

	Game::getTimeManager()->removeTimeout(c->getGameObjectID());

	return 0;
}

Game* PlayScene::game = Game::getInstance();