// TODO
// Add reflection logic later
// for now just make moveable object

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "../Definitions/Definitions.h"
#include "Shapes.h"

class Object
{	
protected:
	int m_velX, m_velY;
	Shape m_shape;
	SpriteID** m_pAnimationList;
	int* m_pAnimationListSize;
	int m_animationIndex;
	AnimationState m_animationState;

public:
// add interfaces later		
	Object(Circle* _pC, SpriteID** _pAnimationList, int* _pAnimationListSize);
	Object(Rect* _pR, SpriteID** _pAnimationList, int* _pAnimationListSize);
	
	~Object();
	void SetVelX(int _velX);
	void SetVelY(int _velY);
	void SetAnimationState(AnimationState _animationState);
	int GetVelX();
	int GetVelY();
	int GetX();
	int GetY();
	SpriteID GetSpriteID();
	virtual void Move();
};

#endif
