#pragma once

#include "Global.h"

#include "Game.h"
#include "Scene.h"
#include "Image.h"
#include "InputManager.h"

#include "Button.h"
#include "Hit.h"
#include "Stand.h"
#include "Pass.h"
#include "DDown.h"
#include "Split.h"

class PlayScene : public Scene
{
public:
	PlayScene();

	void update();
	void render();

	bool onEnter();
	bool onExit();

	void onKeyDown(SDL_Event&);

	void onMouseButtonDown(SDL_Event&);

private:
	Image* bg;
	Hit* hit;
	Button* stand;
	Button* pass;
	Button* ddown;
	Button* split;
};