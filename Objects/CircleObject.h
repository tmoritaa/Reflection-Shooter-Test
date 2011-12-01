#ifndef _CIRCLEOBJECT_H_
#define _CIRCLEOBJECT_H_

#include "Object.h"

class CircleObject : public Object
{
protected:
	Circle m_shape;
	virtual bool checkCollision(CircleObject& obj);
	virtual bool checkCollision(RectObject& obj);

public:
	CircleObject(Circle _c, SpriteID** _pAnimationList, int* _pAnimationListSize);
	virtual float GetX();
	virtual float GetY();
	virtual void Move();
};

#endif
