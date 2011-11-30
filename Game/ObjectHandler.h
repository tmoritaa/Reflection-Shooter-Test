#ifndef _OBJECTHANDLER_H_
#define _OBJECTHANDLER_H_

#include "../Objects/Object.h"
#include "../FileParser/FileParser.h"
#include "../Definitions/Definitions.h"
#include <map>
#include <string>
#include <list>

class ObjectHandler
{
private:
	Object* m_main;
	SPVector m_spVector;
	std::map<std::string, SpriteID> m_spriteLibraryKeys;
	std::list<Object*> m_objectList;

	void initMain();
	void initEnemyOne();

public:
	~ObjectHandler();
	Object* GetMain();
	std::list<Object*>* GetObjectList();
	void SetSPVector(SPVector _spVector);
	void Init();
};

#endif
