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
	Circle GetShape();
	virtual float GetCenterX();
	virtual float GetCenterY();
	virtual void Move();
};

#endif
