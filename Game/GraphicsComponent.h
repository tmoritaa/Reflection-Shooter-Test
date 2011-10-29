#ifndef _GRAPHICSCOMPONENT_H_
#define _GRAPHICSCOMPONENT_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

enum 
{
	SPRITEID_MAINIDLE = 0,
	SPRITEID_MAINLEFT,
	SPRITEID_MAINRIGHT,
	SPRITEID_SIZE,
};

class GraphicsComponent
{
private:
	SDL_Surface* screen;
	SDL_Surface* spriteLibrary[SPRITEID_SIZE];
	bool loadImage(std::string path, int index);
	bool loadFiles();

public:
	GraphicsComponent();
	~GraphicsComponent();
	bool Init();
	bool Draw();


};

#endif
