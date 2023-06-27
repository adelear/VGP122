#pragma once

#include "Global.h"

#include "Game.h"
#include "Scene.h"
#include "Image.h"
#include "Button.h"
#include "InputManager.h"

#include "Card.h"
#include "Deck.h"
#include "Hand.h" 
//#include "Hand.h"  //TODO ADD

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene(); 
	void update();
	void render();

	bool onEnter();
	bool onExit();

	void onKeyDown(SDL_Event&);

	void onMouseButtonDown(SDL_Event&);
	void onMouseButtonUp(SDL_Event&);
	void onMouseMove(SDL_Event&);
	void Deal(); 
	void Hit(); 
	void Split();
	void Stand(); 
	void DoubleDown(); 
	void Pass(); 
	int WinCondition(); 
	void DealerTurn(); 
	void CheckBust(); 
	void CleanUp(); 
	void reloadScene(); 
	void resetGame();  

private:
	Image* bg;
	Image* table;

	Button* hit;
	Button* stand;
	Button* pass;
	Button* dubble;
	Button* split;
	Button* restart; 

	//Card* card;
	
	Deck* deck; 

	Hand* player;
	Hand* dealer;  
	Hand* splitHand;  

	bool canHit;
	bool canSplit; 
	bool hasSplit; 
	bool canDoubleDown; 
	bool gameEnded; 
	bool restartPressed = false; 
	
	int splitCount = 0;

};