#include "Shapes.h"
#include "Object.h"

class RectObject : public Object
{
protected:
	Rect hitBox;

public:
	RectObject(Rect_ r, bool _reflectable, string _path);
	RectObject(int _x, int _y, int _w, int _h, bool _reflectable, string _path);
	Rect GetHitBox();
};
