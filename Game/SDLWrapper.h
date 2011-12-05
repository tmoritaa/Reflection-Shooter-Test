#ifndef _SDLWRAPPER_H_
#define _SDLWRAPPER_H_

#include "SDL/SDL.h"
#include "EventHandler.h"
#include "GraphicsComponent.h"
#include "Logic.h"

class SDLWrapper
{
private:
	EventHandler* m_pEventHandler;
	GraphicsComponent* m_pGraphicsComponent;

public:
	SDLWrapper(ObjectHandler* _pObjectHandler);
	~SDLWrapper();
	bool Init();
	EventHandler* GetEventHandler() const;
	GraphicsComponent* GetGraphicsComponent() const;
};

#endif
