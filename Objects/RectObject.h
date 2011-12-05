#ifndef _RECTOBJECT_H_
#define _RECTOBJECT_H_

#include "Object.h"

class RectObject : public Object
{
protected:
	Rect m_shape;

public:
	RectObject(Rect _c, SpriteID** _pAnimationList, int* _pAnimationListSize);
	Rect GetShape();
	virtual float GetCenterX();
	virtual float GetCenterY();
	virtual void Move();
	virtual bool CheckCollision(CircleObject* obj);
	virtual bool CheckCollision(RectObject* obj);
	virtual bool CheckCollision(Object* obj);
};

#endif
