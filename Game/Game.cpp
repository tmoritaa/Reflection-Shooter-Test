// TODO:
// create recursive makefile and make #include to "Definitions.h"
#include "../Definitions/Definitions.h"
#include "Game.h"
#include <stdio.h>

Game::Game()
{
	m_pObjectHandler = new ObjectHandler();
	m_pLogic = new Logic(m_pObjectHandler);
	m_pSDLWrapper = new SDLWrapper(m_pObjectHandler);
}

Game::~Game()
{
	delete m_pSDLWrapper;
	delete m_pLogic;
	delete m_pObjectHandler;
}

bool Game::IterateOneGameLoop()
{
	EventHandler* pEventHandler = m_pSDLWrapper->GetEventHandler();
	GraphicsComponent* pGraphicsComponent = m_pSDLWrapper->GetGraphicsComponent();

	// Get time at beginning of loop
	pEventHandler->StartTimer();

	// handle events (done by eventhandler)
	if (pEventHandler->HandleEvent())
	{
		// quit
		return FAILURE;
	}

	// below performed by Logic Object
	// calc movements
	m_pLogic->MoveObjects();
	// clean up objects off of screen and in active state
	
	//collision detection
	m_pLogic->DetectCollision();

	// perform action

	// below performed by GC
	// Draw graphics of playfield
	// Draw graphics of state field
	if (pGraphicsComponent->Draw())
	{
		printf("GraphicsComponent failed\n");
		return FAILURE;
	}

	// adjust frame rate
	pEventHandler->AdjustFrameRate();

	return SUCCESS;
}

void Game::Start()
{
	if (m_pSDLWrapper->Init())
	{
		printf("Initialization failed\n");
		return;
	}

	printf("Game Started\n");

	while (IterateOneGameLoop() == SUCCESS);

	printf("Game Ended\n");
}
