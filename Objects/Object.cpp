#include "Object.h"
#include <cassert>

Object::Object(bool _reflectable, string _path)
{
	velX = 0;
	velY = 0;
	reflectable = _reflectable;

	assert(loadSprite(_path));
}

Object::~Object()
{
	SDL_FreeSurface(sprite);
}

void Object::SetVelX(int _velX)
{
	velX = _velX;
}

void Object::SetVelY(int _velY)
{
	velY = _velY;
}

int Object::GetVelX()
{
	return velX;
}

int Object::GetVelY()
{
	return velY;
}

bool loadSprite(string _path)
{
	SDL_Surface* loadedImage = NULL;	

	loadedImage = IMG_Load(_path.c_str());

	if (loadedImage != NULL) 
	{
		sprite = SDL_DisplayFormat(loadedImage);
		SDL_FreeSurface(loadedImage);
		
		if (sprite != NULL) 
		{
			SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format, 0, 0xff, 0xff));
		} 
		else 
		{
			return false;
		}
	} 
	else 
	{
		return false;
	}

	return true;
}
