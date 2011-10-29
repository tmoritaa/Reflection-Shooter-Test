// TODO:
// create recursive makefile and make #include to "Definitions.h"
#include "../Definitions/Definitions.h"
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
		return FAILURE;
	}

	if (pGraphicsComponent->Init())
	{
		return FAILURE;
	}

	SDL_WM_SetCaption("Shooter", NULL);

	return SUCCESS;
}

EventHandler* SDLWrapper::GetEventHandler()
{
	return pEventHandler;
}


GraphicsComponent* SDLWrapper::GetGraphicsComponent()
{
	return pGraphicsComponent;
}

