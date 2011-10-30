#ifndef _GAME_H_
#define _GAME_H_

#include "SDLWrapper.h"
#include "Logic.h"
#include "ObjectHandler.h"

class Game 
{
private:
	ObjectHandler* m_pObjectHandler;
	SDLWrapper* m_pSDLWrapper;
	Logic* m_pLogic;
	bool init();

public:
	Game();
	~Game();
	bool IterateOneGameLoop();
	void Start();

};

#endif
