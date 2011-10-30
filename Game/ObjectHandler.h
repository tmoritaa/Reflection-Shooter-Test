#ifndef _OBJECTHANDLER_H_
#define _OBJECTHANDLER_H_

#include "../Objects/Object.h"

class ObjectHandler
{
private:
	Object* m_main;

public:
	ObjectHandler();
	Object* GetMain();
};

#endif
