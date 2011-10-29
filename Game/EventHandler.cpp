// TODO:
// create recursive makefile and make #include to "Definitions.h"
#include "../Definitions/Definitions.h"
#include "EventHandler.h"

EventHandler::EventHandler()
{
}

//TODO
void EventHandler::handleInput(SDL_Event& event/*, passed main object*/)
{
/*
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
			case SDLK_UP: yVel -= 1; break;
			case SDLK_DOWN: yVel += 1; break;
			case SDLK_LEFT: xVel -= 1; break;
			case SDLK_RIGHT: xVel += 1; break;
		}
	} else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym) {
			case SDLK_UP: yVel += 1; break;
			case SDLK_DOWN: yVel -= 1; break;
			case SDLK_LEFT: xVel += 1; break;
			case SDLK_RIGHT: xVel -= 1; break;
		}
	}
*/
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
			case SDLK_UP: printf("KEYDOWN up\n"); break;
			case SDLK_DOWN: printf("KEYDOWN down\n"); break;
			case SDLK_LEFT: printf("KEYDOWN left\n"); break;
			case SDLK_RIGHT: printf("KEYDOWN right\n"); break;
		}
	} 
	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym) {
			case SDLK_UP: printf("KEYUP up\n"); break;
			case SDLK_DOWN: printf("KEYUP down\n"); break;
			case SDLK_LEFT: printf("KEYUP left\n"); break;
			case SDLK_RIGHT: printf("KEYUP right\n"); break;
		}
	}
}

bool EventHandler::HandleEvent(/*pass main object*/)
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
			handleInput(event/*, pass main object*/);
		}
	}

	return SUCCESS;
}
