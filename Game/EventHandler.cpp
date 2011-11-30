// TODO:
// create recursive makefile and make #include to "Definitions.h"
#include "../Definitions/Definitions.h"
#include "EventHandler.h"
#include "../Objects/Object.h"

EventHandler::EventHandler(ObjectHandler* _pObjectHandler)
{
	m_pObjectHandler = _pObjectHandler;
}

bool EventHandler::handleInput(SDL_Event& event)
{
	Object* main = m_pObjectHandler->GetMain();
	float velX = main->GetVelX();
	float velY = main->GetVelY();
	AnimationState animationState;
	bool quit = false;

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
			case SDLK_w: 
			{
				velY -= GENERAL_VELOCITY;
				printf("KEYDOWN up\n"); 
			} break;
			
			case SDLK_s: 
			{
				velY += GENERAL_VELOCITY;
				printf("KEYDOWN down\n"); 
			} break;
			
			case SDLK_a: 
			{
				velX -= GENERAL_VELOCITY;
				printf("KEYDOWN left\n");
			} break;
			
			case SDLK_d: 
			{
				velX += GENERAL_VELOCITY;
				printf("KEYDOWN right\n"); 
			} break;

			case SDLK_ESCAPE:
			{
				quit = true;
				return quit;
			} break;

			default:
			{
				return quit;
			} break;
		}
	} 
	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym) {
			case SDLK_w: 
			{
				velY += GENERAL_VELOCITY;
				printf("KEYUP up\n"); 
			} break;

			case SDLK_s: 
			{
				velY -= GENERAL_VELOCITY;
				printf("KEYUP down\n"); 
			} break;
			
			case SDLK_a: 
			{
				velX += GENERAL_VELOCITY;
				printf("KEYUP left\n"); 
			} break;
			
			case SDLK_d: 
			{
				velX -= GENERAL_VELOCITY;
				printf("KEYUP right\n"); 
			} break;

			default:
			{
				return quit;
			}
		}
	}

	if (velX > 0)
	{
		animationState = ANIMATIONSTATE_RIGHT;
	}
	else if (velX < 0)
	{
		animationState = ANIMATIONSTATE_LEFT;
	}
	else
	{
		animationState = ANIMATIONSTATE_IDLE;
	}

	main->SetVelX(velX);
	main->SetVelY(velY);

	if (animationState != ANIMATIONSTATE_SIZE)
	{
		main->SetAnimationState(animationState);
	}

	return quit;
}

bool EventHandler::HandleEvent()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || handleInput(event))
		{
			return FAILURE;
		}
	}

	return SUCCESS;
}

void EventHandler::StartTimer()
{
	timer.startTick = SDL_GetTicks();
}

void EventHandler::AdjustFrameRate()
{
	if (timer.startTick < (1000/FRAMERATE))
	{
		SDL_Delay((1000/FRAMERATE) - timer.startTick);
	}
}
