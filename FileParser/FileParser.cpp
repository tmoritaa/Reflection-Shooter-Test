#include "FileParser.h"
#include <fstream>
#include <cassert>

using namespace std;

bool isNum(char ch);
int convertToNum(char ch);
string convertToStateName(const string oriName, const ObjectState state);

SPVector FileParser::ParseInipFile(string filePath)
{
	fstream spritePaths(filePath.c_str());

	string line;
	int index = 0;
	int curID = 0;
	string name;

	SPVector spVector;
	struct SpritePath tempSP;

	ParseState parseState = PARSE_NAME;
	ObjectState objState = OBJSTATE_INVALID;

	assert(spritePaths.is_open());

	while(spritePaths.good())
	{
		getline(spritePaths, line);

		if (line == "" || line[0] == '#')
		{
			continue;
		}

		switch (parseState)
		{
			case PARSE_NAME:
			{
				name = line;
				parseState = PARSE_PATH;
			} break;

			case PARSE_PATH:
			{
				if (isNum(line[0]))
				{
					index = 1;
					tempSP.aniLength = convertToNum(line[0]);
					tempSP.objID = curID;
					objState = (ObjectState) (((int)objState) + 1);
				}
				// go to next object parse
				else if (line[0] == '$')
				{
					parseState = PARSE_NAME;
					objState = OBJSTATE_INVALID;

					tempSP.objID = 0;
					tempSP.aniLength = 0;
					tempSP.name = "";
					tempSP.path = "";
					
					index = 1;
					curID++;
				}
				else 
				{
					tempSP.path = line;
					tempSP.name = convertToStateName(name, objState);
					if (tempSP.aniLength > 1)
					{
						char num = index + '0';
						tempSP.name += num;
						index++;
					}

					spVector.push_back(tempSP);

					tempSP.name = "";
					tempSP.path = "";
				}
			} break;

			default:
			{
				assert(0 && "File Parse failed due to invalid parse state");
			} break;	
		}

		line = "";
	}

	return spVector;
}

string convertToStateName(const string oriName, const ObjectState state)
{
	string name;

	switch (state)
	{
		case OBJSTATE_IDLE:
		{
			name = oriName + "idle";
		} break;

		case OBJSTATE_LEFT:
		{
			name = oriName + "left";
		} break;

		case OBJSTATE_RIGHT:
		{
			name = oriName + "right";
		} break;

		case OBJSTATE_UP:
		{
			name = oriName + "up";
		} break;

		case OBJSTATE_DOWN:
		{
			name = oriName + "down";
		} break;

		case OBJSTATE_OTHER1:
		{
			name = oriName + "other1";
		} break;

		case OBJSTATE_OTHER2:
		{
			name = oriName + "other2";
		} break;

		case OBJSTATE_OTHER3:
		{
			name = oriName + "other3";
		} break;

		default:
		{
			assert(0 && "convertToStateName: invalid object state given");
		}
	}

	return name;
}

bool isNum(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return true;
	}

	return false;
}

int convertToNum(char ch)
{
	assert(isNum(ch));

	return (ch - '0');
}

