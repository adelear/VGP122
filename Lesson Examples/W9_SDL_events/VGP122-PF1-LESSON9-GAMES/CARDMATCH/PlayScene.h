#pragma once

#include <iostream>
#include <vector>

#include "Game.h"
#include "Scene.h"
#include "Image.h"
#include "InputManager.h"

#include "Global.h"
#include "Deck.h"
#include "Card.h"
#include "Selector.h"

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene() = default;

	void update();
	void render();

	bool onEnter();
	bool onExit();

	void onKeyDown(SDL_Event&);

private:
	Image* bg;
	Deck* deck;
	Selector* selector;

	bool pair;
	Card* hand1;
	Card* hand2;

	int currentCard;
	int score;
};