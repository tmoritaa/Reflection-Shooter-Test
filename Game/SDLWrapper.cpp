// TODO:
// create recursive makefile and make #include to "Definitions.h"
#include "../Definitions/Definitions.h"
#include "SDLWrapper.h"

SDLWrapper::SDLWrapper(ObjectHandler* _pObjectHandler)
{
	m_pEventHandler = new EventHandler(_pObjectHandler);
	m_pGraphicsComponent = new GraphicsComponent(_pObjectHandler);
}

SDLWrapper::~SDLWrapper()
{
	delete m_pEventHandler;
	delete m_pGraphicsComponent;
}

bool SDLWrapper::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) == -1)
	{
		return FAILURE;
	}

	if (m_pGraphicsComponent->Init())
	{
		return FAILURE;
	}

	SDL_WM_SetCaption("Shooter", NULL);

	return SUCCESS;
}

EventHandler* SDLWrapper::GetEventHandler() const
{
	return m_pEventHandler;
}


GraphicsComponent* SDLWrapper::GetGraphicsComponent() const
{
	return m_pGraphicsComponent;
}

