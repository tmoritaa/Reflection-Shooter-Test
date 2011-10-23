#include "SDLWrapper.h"

SDLWrapper::SDLWrapper()
{
	pEventHandler = new EventHandler();
	pGraphicsComponent = new GraphicsComponent();
}

bool SDLWrapper::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) == -1)
	{
		return true;
	}

	if (pGraphicsComponent->Init())
	{
		return true;
	}

	SDL_WM_SetCaption("Shooter", NULL);

	return false;
}

EventHandler* SDLWrapper::GetEventHandler()
{
	return pEventHandler;
}


GraphicsComponent* SDLWrapper::GetGraphicsComponent()
{
	return pGraphicsComponent;
}

