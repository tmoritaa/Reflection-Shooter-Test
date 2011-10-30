#ifndef _GRAPHICSCOMPONENT_H_
#define _GRAPHICSCOMPONENT_H_

#include "ObjectHandler.h"
#include "../Definitions/Definitions.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class GraphicsComponent
{
private:
	ObjectHandler* m_pObjectHandler;
	SDL_Surface* m_screen;
	SDL_Surface* m_spriteLibrary[SPRITEID_SIZE];
	bool loadFiles();
	bool loadImage(const char* path, int index);
	void drawObject(Object* _object);

public:
	GraphicsComponent(ObjectHandler* _pObjectHandler);
	~GraphicsComponent();
	bool Init();
	bool Draw();
};

#endif
