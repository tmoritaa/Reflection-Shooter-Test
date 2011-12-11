#ifndef _RECTOBJECT_H_
#define _RECTOBJECT_H_

#include "Object.h"

class RectObject : public Object
{
protected:
	Rect m_shape;

public:
	RectObject();
	RectObject(Rect _c, SpriteID** _pAnimationList, int* _pAnimationListSize);
	Rect GetShape() const;
	virtual float GetCenterX() const;
	virtual float GetCenterY() const;
	virtual void Move();
	virtual bool CheckCollision(const CircleObject* obj) const;
	virtual bool CheckCollision(const RectObject* obj) const;
	virtual bool CheckCollision(Object* obj) const;
};

#endif
