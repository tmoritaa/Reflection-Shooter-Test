// TODO:
// create recursive makefile and make #include to "Definitions.h"
#include "GraphicsComponent.h"
#include <fstream>
#include <cstdio>
#include <string>
#include <cassert>
#include <list>

using namespace std;

GraphicsComponent::GraphicsComponent(ObjectHandler* _pObjectHandler)
{
	m_pObjectHandler = _pObjectHandler;

	m_screen = NULL;
}

GraphicsComponent::~GraphicsComponent()
{
	SDL_FreeSurface(m_screen);
	m_screen = NULL;

	for (int i = 0; i < m_spriteLibrary.size(); i++)
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

	// must be initialized after SPVector in ObjectHandler is initialized
	m_pObjectHandler->Init();

	return SUCCESS;
}

bool GraphicsComponent::loadFiles()
{
	SPVector spVector;
	FileParser fileParser;
	bool bSuccess = SUCCESS;

	spVector = fileParser.ParsePiniFile("Sprites/SpritePaths.pini");
	struct SpritePath spritePath;

	for (int i = 0; i < spVector.size(); i++)
	{
		spritePath = spVector[i];

		if (loadImage(spritePath, i) == FAILURE)
		{
			printf("Image Loading failed\n");
			bSuccess = FAILURE;
			break;
		}
	}

	m_pObjectHandler->SetSPVector(spVector);

	return bSuccess;
}

bool GraphicsComponent::loadImage(const struct SpritePath sp, int index)
{
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;

	string path = sp.path;

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

	m_spriteLibrary.push_back(optimizedImage);

	return SUCCESS;
}

bool GraphicsComponent::Draw() 
{
	list<Object*>* objectList = m_pObjectHandler->GetObjectList();

	// fill background white for now
	SDL_FillRect(m_screen, &m_screen->clip_rect, SDL_MapRGB(m_screen->format, 0xff, 0xff, 0xff));

	// TODO
	// Go through ObjectList and draw each object with for loop
	// for now just main
	for (list<Object*>::iterator i = objectList->begin(); i != objectList->end(); i++)
	{
		drawObject(*i);
	}

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
	offset.x = _object->GetCenterX();
	offset.y = _object->GetCenterY();

	SDL_Surface* src = m_spriteLibrary[spriteID];

	SDL_BlitSurface(src, NULL, m_screen, &offset);
}
