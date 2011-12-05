#ifndef _CIRCLEOBJECT_H_
#define _CIRCLEOBJECT_H_

#include "Object.h"

class CircleObject : public Object
{
protected:
	Circle m_shape;

public:
	CircleObject(Circle _c, SpriteID** _pAnimationList, int* _pAnimationListSize);
	Circle GetShape();
	virtual float GetCenterX();
	virtual float GetCenterY();
	virtual void Move();
	virtual bool CheckCollision(CircleObject* obj);
	virtual bool CheckCollision(RectObject* obj);
	virtual bool CheckCollision(Object* obj);
};

#endif
