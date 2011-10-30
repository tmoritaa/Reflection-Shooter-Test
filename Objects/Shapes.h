#ifndef _SHAPE_H_
#define _SHAPE_H_

struct Circle
{
	int x, y;
	int r;
};

struct Rect
{
	int x, y;
	int w, h;
};

struct Shape
{
	Circle* c;
	Rect* r;
};

#endif
