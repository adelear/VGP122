#pragma once

#include "Global.h"

#include "Game.h"
#include "Scene.h"
#include "Image.h"
#include "Vector2D.h"
#include "InputManager.h"
#include "SceneManager.h"

#include "Button.h"

class MenuScene : public Scene
{
public:
	MenuScene();

	void update();
	void render();

	bool onEnter();
	bool onExit();

	void onKeyDown(SDL_Event&);

	void onMouseButtonDown(SDL_Event&);

private:
	Image* bg;
	Image* logo;
	Button* play;
};