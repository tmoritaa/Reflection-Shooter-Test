#include <stdio.h>
#include "FileParser.h"
#include <string>

using namespace std;

int main (int argc, char* argv[])
{
	FileParser fileParser;

	SPVector spVector;

	spVector = fileParser.ParseInipFile("Sprites/SpritePaths.pini");

	for (int i = 0; i < spVector.size(); i++)
	{
		struct SpritePath sp = spVector[i];

		printf("struct %d\n", i);
		printf("objID: %d\n", sp.objID);
		printf("aniLength: %d\n", sp.aniLength);
		printf("name: %s\n", sp.name.c_str());
		printf("path: %s\n", sp.path.c_str());
		printf("\n");
	}

	return 0;
}
