#ifndef _OBJECTHANDLER_H_
#define _OBJECTHANDLER_H_

#include "../Objects/Object.h"
#include "../FileParser/FileParser.h"
#include "../Definitions/Definitions.h"
#include <map>
#include <string>

class ObjectHandler
{
private:
	Object* m_main;
	SPVector m_spVector;
	std::map<std::string, SpriteID> m_spriteLibraryKeys;

	void initMain();

public:
	~ObjectHandler();
	Object* GetMain();
	void SetSPVector(SPVector _spVector);
	void Init();
};

#endif
