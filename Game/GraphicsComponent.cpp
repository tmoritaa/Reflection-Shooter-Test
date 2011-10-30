// TODO:
// create recursive makefile and make #include to "Definitions.h"
// add pointer to GameLogic
#include "../Definitions/Definitions.h"
#include "GraphicsComponent.h"
#include <fstream>
#include <cstdio>
#include <cassert>
#include <string>

using namespace std;

GraphicsComponent::GraphicsComponent(ObjectHandler* _pObjectHandler)
{
	m_pObjectHandler = _pObjectHandler;

	m_screen = NULL;
	for (int i = 0; i < SPRITEID_SIZE; i++)
	{
		m_spriteLibrary[i] = NULL;
	}
}

GraphicsComponent::~GraphicsComponent()
{
	SDL_FreeSurface(m_screen);
	m_screen = NULL;

	for (int i = 0; i < SPRITEID_SIZE; i++)
	{
		if (m_spriteLibrary[i] != NULL) 
		{
			SDL_FreeSurface(m_spriteLibrary[i]);
			m_spriteLibrary[i] = NULL;
		}
	}
}

bool GraphicsComponent::Init()
{
	m_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	
	if (m_screen == NULL)
	{
		return FAILURE;
	}

	if (loadFiles() == FAILURE)
	{
		return FAILURE;
	}

	return SUCCESS;
}

bool GraphicsComponent::loadFiles()
{
	fstream spritePaths("Sprites/SpritePaths.ini");
	string line;
	int i = 0;
	bool bSuccess = SUCCESS;

	assert(spritePaths.is_open());

	while(spritePaths.good())
	{
		getline(spritePaths, line);

		if (line == "")
		{
			continue;
		}

		if (loadImage(line.c_str(), i) == FAILURE)
		{
			printf("Image Loading failed\n");
			bSuccess = FAILURE;
			break;
		}

		i++;
	}

	return bSuccess;
}

bool GraphicsComponent::loadImage(const char* path, int index)
{
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;

	loadedImage = IMG_Load(path);

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

	m_spriteLibrary[index] = optimizedImage;

	return SUCCESS;
}

bool GraphicsComponent::Draw()
{
	// fill background white for now
	SDL_FillRect(m_screen, &m_screen->clip_rect, SDL_MapRGB(m_screen->format, 0xff, 0xff, 0xff));

	// TODO
	// Go through ObjectList and draw each object with for loop
	// for now just main
	drawObject(m_pObjectHandler->GetMain());

	if (SDL_Flip(m_screen) == -1)
	{
		return FAILURE;
	}

	return SUCCESS;
}

void GraphicsComponent::drawObject(Object* _object)
{
	SpriteID spriteID = _object->GetSpriteID();

	SDL_Rect offset;
	offset.x = _object->GetX();
	offset.y = _object->GetY();

	SDL_Surface* src = m_spriteLibrary[spriteID];

	SDL_BlitSurface(src, NULL, m_screen, &offset);
}
