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
	float m_velX, m_velY;
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
	void SetVelX(float _velX);
	void SetVelY(float _velY);
	void SetAnimationState(AnimationState _animationState);
	float GetVelX();
	float GetVelY();
	float GetX();
	float GetY();
	SpriteID GetSpriteID();
	virtual void Move();
};

#endif
