#ifndef _RECTOBJECT_H_
#define _RECTOBJECT_H_

#include "Object.h"

class RectObject : public Object
{
protected:
	Rect m_shape;
	virtual bool checkCollision(CircleObject& obj);
	virtual bool checkCollision(RectObject& obj);

public:
	RectObject(Rect _c, SpriteID** _pAnimationList, int* _pAnimationListSize);
	virtual float GetX();
	virtual float GetY();
	virtual void Move();
};

#endif
