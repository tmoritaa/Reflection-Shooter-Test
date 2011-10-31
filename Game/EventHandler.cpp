// TODO:
// create recursive makefile and make #include to "Definitions.h"
#include "../Definitions/Definitions.h"
#include "EventHandler.h"
#include "../Objects/Object.h"

EventHandler::EventHandler(ObjectHandler* _pObjectHandler)
{
	m_pObjectHandler = _pObjectHandler;
}

void EventHandler::handleInput(SDL_Event& event)
{
	Object* main = m_pObjectHandler->GetMain();
	int velX = main->GetVelX();
	int velY = main->GetVelY();
	AnimationState animationState = ANIMATIONSTATE_SIZE;

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
			case SDLK_UP: 
			{
				velY -= GENERAL_VELOCITY;
				printf("KEYDOWN up\n"); 
			} break;
			
			case SDLK_DOWN: 
			{
				velY += GENERAL_VELOCITY;
				printf("KEYDOWN down\n"); 
			} break;
			
			case SDLK_LEFT: 
			{
				velX -= GENERAL_VELOCITY;
				animationState = ANIMATIONSTATE_LEFT; 
				printf("KEYDOWN left\n");
			} break;
			
			case SDLK_RIGHT: 
			{
				velX += GENERAL_VELOCITY;
				animationState = ANIMATIONSTATE_RIGHT; 
				printf("KEYDOWN right\n"); 
			} break;
		}
	} 
	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym) {
			case SDLK_UP: 
			{
				velY += GENERAL_VELOCITY;
				printf("KEYUP up\n"); 
			} break;

			case SDLK_DOWN: 
			{
				velY -= GENERAL_VELOCITY;
				printf("KEYUP down\n"); 
			} break;
			
			case SDLK_LEFT: 
			{
				velX += GENERAL_VELOCITY;
				animationState = ANIMATIONSTATE_IDLE; 
				printf("KEYUP left\n"); 
			} break;
			
			case SDLK_RIGHT: 
			{
				velX -= GENERAL_VELOCITY;
				animationState = ANIMATIONSTATE_IDLE; 
				printf("KEYUP right\n"); 
			} break;
		}
	}

	main->SetVelX(velX);
	main->SetVelY(velY);

	if (animationState != ANIMATIONSTATE_SIZE)
	{
		main->SetAnimationState(animationState);
	}
}

bool EventHandler::HandleEvent()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			return FAILURE;
		}
		else 
		{
			handleInput(event);
		}
	}

	return SUCCESS;
}
