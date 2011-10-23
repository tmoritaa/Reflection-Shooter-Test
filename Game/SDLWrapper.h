#ifndef _SDLWRAPPER_H_
#define _SDLWRAPPER_H_

#include "SDL/SDL.h"
#include "EventHandler.h"
#include "GraphicsComponent.h"

class SDLWrapper
{
private:
	EventHandler* pEventHandler;
	GraphicsComponent* pGraphicsComponent;

public:
	SDLWrapper();
	bool Init();
	EventHandler* GetEventHandler();
	GraphicsComponent* GetGraphicsComponent();
};

#endif
