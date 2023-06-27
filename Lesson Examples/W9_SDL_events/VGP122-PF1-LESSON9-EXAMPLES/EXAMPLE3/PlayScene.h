#pragma once

#include <iostream>
#include <vector>

#include "Game.h"
#include "Scene.h"
#include "Image.h"
#include "InputManager.h"

#include "Global.h"

#include "Wall.h"
#include "Character.h"

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
	void onKeyUp(SDL_Event&);

private:
	Image* bg;
	Wall* ground;
	Wall* leftWall;
	Wall* rightWall;
	Character* ken;

	static Game* game;
};