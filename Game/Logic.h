#ifndef _LOGIC_H_
#define _LOGIC_H_

// TODO 
// make recursive makefile with INCLUDE definitions
#include "../Definitions/Definitions.h"
#include "ObjectHandler.h"

class Logic
{
private:
	ObjectHandler* m_pObjectHandler;

public:
	Logic(ObjectHandler* _pObjectHandler);
	void MoveObjects();
	void DetectCollision();
};

#endif
