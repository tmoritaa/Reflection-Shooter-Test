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
		return true;
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
		return true;
	}

	// adjust frame rate


	return false;
}

void Game::Start()
{
	if (pSDLWrapper->Init())
	{
		return;
	}

	printf("Game Started\n");

	while (!IterateOneGameLoop());

	printf("Game Ended\n");
}
