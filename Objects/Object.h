#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

class Object
{	
protected:
	int velX, velY;
	bool reflectable;	
	SDL_Surface* sprite;	

	bool loadSprite(string path);

public:
// add interfaces later		
	Object(bool _reflectable);
	virtual ~Object();
	void SetVelX(int _velX);
	void SetVelY(int _velY);
	int GetVelX();
	int GetVelY();
};
