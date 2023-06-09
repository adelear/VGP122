#include <iostream>
#include <cstdlib>

#include "SDL.h"

using namespace std;

int main(int argv, char** argc)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		cerr << "Unable to initialize SDL" << SDL_GetError() << endl;

		return -1;
	}

	atexit(SDL_Quit);

	cout << "SDL initialized" << endl;

	return 0;
}