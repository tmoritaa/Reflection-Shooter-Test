#ifndef _GRAPHICSCOMPONENT_H_
#define _GRAPHICSCOMPONENT_H_

#include "ObjectHandler.h"
#include "../Definitions/Definitions.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <vector>

typedef std::vector<SDL_Surface*> SurfaceVector;

class GraphicsComponent
{
private:
	ObjectHandler* m_pObjectHandler;
	SDL_Surface* m_screen;
	SurfaceVector m_spriteLibrary;

	bool loadFiles();
	bool loadImage(const struct SpritePath sp, int index);
	void drawObject(Object* _object);

public:
	GraphicsComponent(ObjectHandler* _pObjectHandler);
	~GraphicsComponent();
	bool Init();
	bool Draw();
};

#endif
