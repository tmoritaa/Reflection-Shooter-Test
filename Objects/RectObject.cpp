#include "RectObject.h"

RectObject::RectObject(Rect_r, bool _reflectable, string _path)
:	Object(_reflectable, _path)
{
	hitBox.x = _r.x;
	hitBox.y = _r.y;
	hitBox.w = _r.w;
	hitBox.h = _r.h;
}

RectObject::RectObject(int _x, int _y, int _w, int _h, bool _reflectable, string _path)
:	Object(_reflectable, _path)
{
	hitBox.x = _x;
	hitBox.y = _y;
	hitBox.w = _w;
	hitBox.h = _h;
}

Rect RectObject::GetHitBox()
{
	return hitBox;
}
