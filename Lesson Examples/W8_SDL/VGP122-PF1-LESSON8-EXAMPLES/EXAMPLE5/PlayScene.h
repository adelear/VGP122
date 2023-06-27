#pragma once

#include "Global.h"

#include "Game.h"
#include "Scene.h"
#include "Image.h"
#include "Cursor.h"
#include "InputManager.h"

class PlayScene : public Scene
{
public:
	PlayScene();

	void update();
	void render();

	bool onEnter();
	bool onExit();

	void onKeyDown(SDL_Event&);

	void onControllerButtonDown(SDL_Event&);
	void onControllerAxisMotion(SDL_Event&);

private:
	Image* bg;
	Image* charSelect;
	Cursor* cursor1;
	Cursor* cursor2;
};