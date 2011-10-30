#ifndef _EVENTHANDLER_H_
#define _EVENTHANDLER_H_

#include "SDL/SDL.h"
#include "ObjectHandler.h"
#include "../Definitions/Definitions.h"

class EventHandler
{
private:
	ObjectHandler* m_pObjectHandler;
	void handleInput(SDL_Event& event);

public:
	EventHandler(ObjectHandler* _pObjectHandler);
	bool HandleEvent();
	
};

#endif
