#include "Shapes.h"
#include "Object.h"

class CircleObject : public Object
{
protected:
	Circle hitBox;

public:
	CircleObject(Circle _c, bool _reflectable, string _path);
	CircleObject(int _x, int _y, int _r, bool _reflectable, string _path);
	Circle GetHitBox();
};
