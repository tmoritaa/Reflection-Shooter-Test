#ifndef _FILEPARSER_H_
#define _FILEPARSER_H_

#include "../Definitions/Definitions.h"

enum ParseState 
{
	PARSE_NAME = 1,
	PARSE_PATH,
};

// Number of Sprite AnimationStates are currently predetermined. (Idle, left, right, up, down, other1, other2, other3)
enum ObjectState
{
	OBJSTATE_INVALID = 0,
	OBJSTATE_IDLE,
	OBJSTATE_LEFT,
	OBJSTATE_RIGHT,
	OBJSTATE_UP,
	OBJSTATE_DOWN,
	OBJSTATE_OTHER1,
	OBJSTATE_OTHER2,
	OBJSTATE_OTHER3,
};

class FileParser
{
private:

public:
	 SPVector ParsePiniFile(const std::string  _filePath) const;
};

#endif
