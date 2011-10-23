#ifndef _GAME_H_
#define _GAME_H_

#include "SDLWrapper.h"
//#include "GameLogic.h"

class Game 
{
private:
	SDLWrapper* pSDLWrapper;
	//GameLogic* pGameLogic;
	bool init();

public:
	Game();
	bool IterateOneGameLoop();
	void Start();

};

#endif
