#pragma once

#include <string>

#include "SDL.h"

// **********************************************
// Global Screen Resolution - change these values
// **********************************************
static const int SCREEN_WIDTH = 512;
static const int SCREEN_HEIGHT = 384;

// *************************************
// Global Game Title - change this value
// *************************************
const std::string GAME_TITLE = "CARD MATCH";

// ****************************************************
// Global Initial Window Position - change these values
// ****************************************************
const int XPOS = SDL_WINDOWPOS_CENTERED;
const int YPOS = SDL_WINDOWPOS_CENTERED;

const int NUMCARDS = 18;
const int ROWS = 3;
const int COLS = 6;

typedef enum face
{
	BLANK = 0,
	CHEST = 6,
	COIN = 7,
	FLOWER = 8,
	MUSHROOM = 9,
	STAR = 10
} FACES;