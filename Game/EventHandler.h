#ifndef _EVENTHANDLER_H_
#define _EVENTHANDLER_H_

#include "SDL/SDL.h"
#include "ObjectHandler.h"
#include "../Definitions/Definitions.h"

struct Timer
{
	int startTick;
};

class EventHandler
{
private:
	ObjectHandler* m_pObjectHandler;
	bool handleInput(SDL_Event& event);
	Timer timer;

public:
	EventHandler(ObjectHandler* _pObjectHandler);
	bool HandleEvent();
	void StartTimer();
	void AdjustFrameRate() const;
};

#endif
