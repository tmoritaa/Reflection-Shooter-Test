#ifndef _SHAPE_H_
#define _SHAPE_H_

struct Circle
{
	float x, y;
	float r;

	Circle()
	{
		x = y = r = 0;
	}
};

struct Rect
{
	float x, y;
	float w, h;

	Rect()
	{
		x = y = w = h = 0;
	}
};

#endif
