#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent()
{
}

bool GraphicsComponent::loadImages()
{




}

bool GraphicsComponent::Init()
{
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	
	if (screen == NULL)
	{
		return true;
	}

	if (loadImages())
	{
		return true;
	}

	return false;
}


bool GraphicsComponent::Draw()
{
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xff, 0xff, 0xff));

	if (SDL_Flip(screen) == -1)
	{
		return true;
	}

	return false;
}

