// TODO:
// create recursive makefile and make #include to "Definitions.h"
#include "../Definitions/Definitions.h"
#include "GraphicsComponent.h"
#include <fstream>

using namespace std;

GraphicsComponent::GraphicsComponent()
{
	screen = NULL;
	for (int i = 0; i < SPRITEID_SIZE; i++)
	{
		spriteLibrary[i] = NULL;
	}
}

GraphicsComponent::~GraphicsComponent()
{
	SDL_FreeSurface(screen);
	screen = NULL;

	for (int i = 0; i < SPRITEID_SIZE; i++)
	{
		if (spriteLibrary[i] != NULL) 
		{
			SDL_FreeSurface(spriteLibrary[i]);
			spriteLibrary[i] = NULL;
		}
	}
}

bool GraphicsComponent::loadImage(string path, int index)
{
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;

	loadedImage = IMG_Load(path.c_str());

	if (loadedImage == NULL)
	{
		return FAILURE;
	}

	optimizedImage = SDL_DisplayFormat(loadedImage);
	SDL_FreeSurface(loadedImage);

	if (optimizedImage == NULL)
	{
		return FAILURE;
	}

	SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB(optimizedImage->format, 0x0, 0xff, 0xff));

	spriteLibrary[index] = optimizedImage;

	return SUCCESS;
}

bool GraphicsComponent::loadFiles()
{
	ifstream spritePaths("SpritePath.ini");
	string line;
	int i = 0;

	if (spritePaths.is_open())
	{
		getline(spritePaths, line);

		if (loadImage(line, i) == FAILURE)
		{
			return FAILURE;
		}

		i++;
	}

	return SUCCESS;
}

bool GraphicsComponent::Init()
{
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	
	if (screen == NULL)
	{
		return FAILURE;
	}

	if (loadFiles() == FAILURE)
	{
		return FAILURE;
	}

	return SUCCESS;
}


bool GraphicsComponent::Draw()
{
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xff, 0xff, 0xff));

	if (SDL_Flip(screen) == -1)
	{
		return FAILURE;
	}

	return SUCCESS;
}

