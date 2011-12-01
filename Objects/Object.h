// TODO
// Add reflection logic later
// for now just make moveable object

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "../Definitions/Definitions.h"
#include "Shapes.h"

class CircleObject;
class RectObject;

class Object
{	
protected:
	float m_velX, m_velY;
	SpriteID** m_pAnimationList;
	int* m_pAnimationListSize;
	int m_animationIndex;
	AnimationState m_animationState;
	
	float distance(float x1, float y1, float x2, float y2);

public:
	Object(SpriteID** _pAnimationList, int* _pAnimationListSize);
	~Object();
	void SetVelX(float _velX);
	void SetVelY(float _velY);
	void SetAnimationState(AnimationState _animationState);
	float GetVelX();
	float GetVelY();
	SpriteID GetSpriteID();

	virtual float GetCenterX() = 0;
	virtual float GetCenterY() = 0;
	virtual void Move();
};

#endif
