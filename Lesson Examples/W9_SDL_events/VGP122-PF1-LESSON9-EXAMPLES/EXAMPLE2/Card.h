#pragma once

#include <string>
#include <vector>

#include "Global.h"

#include "Vector2D.h"
#include "Game.h"
#include "GameObject.h"
#include "Sprite.h"

class Card : public GameObject
{
public:
	Card(std::string, std::string, int, int, int, int, int, int, int);
	Card(const Card&);
	~Card();

	void initialize();

	void update();
	void render();

	Card* clone();

	void play(std::string, int, bool = false, bool = false);

	void setPosition(Vector2D);
	Vector2D getPosition();

	void setCurrentFrame(int);

	void setFace(int);
	int getFace();

	bool isTurned();
	void setTurned(bool);
	
	std::string getFaceName();

	Sprite* graphic;

private:
	int face;
	bool turned;

	static const std::vector<int> chestAnimation;
	static const std::vector<int> coinAnimation;
	static const std::vector<int> flowerAnimation;
	static const std::vector<int> mushroomAnimation;
	static const std::vector<int> starAnimation;
};