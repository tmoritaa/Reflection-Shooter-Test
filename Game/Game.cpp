// TODO:
// create recursive makefile and make #include to "Definitions.h"
#include "../Definitions/Definitions.h"
#include "Game.h"
#include <stdio.h>

Game::Game()
{
	pSDLWrapper = new SDLWrapper;
}

bool Game::IterateOneGameLoop()
{
	EventHandler* pEventHandler = pSDLWrapper->GetEventHandler();
	GraphicsComponent* pGraphicsComponent = pSDLWrapper->GetGraphicsComponent();

	// handle events (done by eventhandler)
	if (pEventHandler->HandleEvent(/*pass main object*/))
	{
		return FAILURE;
	}

	// below performed by Logic Object
	// calc movements
	// clean up objects off of screen and in active state
	//collision detection
	// perform action

	// below performed by GC
	// Draw graphics of playfield
	// Draw graphics of state field
	if (pGraphicsComponent->Draw())
	{
		return FAILURE;
	}

	// adjust frame rate


	return SUCCESS;
}

void Game::Start()
{
	if (pSDLWrapper->Init())
	{
		return;
	}

	printf("Game Started\n");

	while (IterateOneGameLoop() == SUCCESS);

	printf("Game Ended\n");
}
