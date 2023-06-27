#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "SDL.h"
#include "SDL_image.h"

#include "Game.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "AnimationManager.h"
#include "Vector2D.h"

class Sprite : public GameObject
{
public:
	Sprite(std::string, std::string, int, int, int = 0, int = 0, int = 0, int = 0, double = 0.0, SDL_RendererFlip = SDL_FLIP_NONE);
	~Sprite();

	virtual void update();
	virtual void render();

	void addAnimation(std::string, const std::vector<int>);

	void play(int, int, int, bool = true, bool = false, bool = SDL_FLIP_NONE);
	void play(std::string, int, bool = true, bool = false, bool = SDL_FLIP_NONE);
	void stop();

	void move(int, int);
	void gotoPos(int, int);

	SDL_Rect getRect();

	void setCurrentFrame(int);
	int getCurrentFrame();

	SDL_Texture* getFrame();

	bool isAnimating();
	bool isVisible();
	void setVisible(bool);

	Uint32 getDelta();

	SDL_RendererFlip flipFlag;

	Vector2D position;

	double angle;

protected:
	void load();

	std::vector<int> currentSequence;
	std::string currentAnimation;
	int currentFrame;
	int startFrame;
	int endFrame;

	int fps;
	Uint32 startTime;

	bool animating;
	bool repeat;
	bool reverse;

	int textureWidth;
	int textureHeight;

	int rows;
	int cols;
	int offsetX;
	int offsetY;

	bool visible;

	std::string filename;

	ResourceManager* resourceManager;
	AnimationManager* animationManager;
	TimeManager* timeManager;

	SDL_Texture* texture;
	SDL_Renderer* renderer;
};