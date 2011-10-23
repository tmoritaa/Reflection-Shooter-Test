#include "CircleObject.h"

CircleObject::CircleObject(Circle _c, bool _reflectable, string _path)
:	Object(_reflectable, _path)
{
	hitBox.x = _c.x;
	hitBox.y = _c.y;
	hitBox.r = _c.r;
}

CircleObject::CircleObject(int _x, int _y, int _r, bool _reflectable, string _path)
: 	Object(_reflectable, _path)
{
	hitBox.x = _x;
	hitBox.y = _y;
	hitBox.r = _r;
}

Circle CircleObject::GetHitBox()
{
	return hitBox;
}
