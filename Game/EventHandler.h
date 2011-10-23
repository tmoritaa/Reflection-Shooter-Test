#ifndef _EVENTHANDLER_H_
#define _EVENTHANDLER_H_

#include "SDL/SDL.h"

class EventHandler
{
private:
	void handleInput(SDL_Event& event);

public:
	EventHandler();
	//TODO
	bool HandleEvent(/*pass main object*/);
	
};

#endif
