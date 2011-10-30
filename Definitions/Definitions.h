#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

// TODO
// maybe separate definitions based on relationship
const bool SUCCESS = false;
const bool FAILURE = true;

typedef unsigned char BYTE;
typedef unsigned int SpriteID;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

const int GENERAL_VELOCITY = 1;

enum
{
	SPRITEID_MAINIDLE = 0,
	SPRITEID_MAINLEFT,
	SPRITEID_MAINRIGHT,
	SPRITEID_SIZE,
};


#endif
