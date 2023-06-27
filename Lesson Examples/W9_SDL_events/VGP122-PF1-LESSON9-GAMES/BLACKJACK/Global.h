#pragma once

#include <string>

#include "SDL.h"

// **********************************************
// Global Screen Resolution - change these values
// **********************************************
static const int SCREEN_WIDTH = 2048;
static const int SCREEN_HEIGHT = 1536;

// *************************************
// Global Game Title - change this value
// *************************************
const std::string GAME_TITLE = "BLACKJACK";

// ****************************************************
// Global Initial Window Position - change these values
// ****************************************************
const int XPOS = SDL_WINDOWPOS_CENTERED;
const int YPOS = SDL_WINDOWPOS_CENTERED;

const int NUMCARDS = 52;

typedef enum buttonui
{
	PLAY = 0,
	HIT,
	STAND,
	PASS,
	DDOWN,
	SPLIT
} ButtonUI;