#include "TileCompManager.h"


void TileCompManager::set(GLuint ID, GLuint VAOid, GLuint verticeNumber)
{
	tilestruct newstruct;
	newstruct.type = VAOid;
	newstruct.verticeCount = verticeNumber;
	map[ID] = newstruct;
}

void TileCompManager::remove(GLuint ID)
{
	map.erase(ID);
}

void TileCompManager::cleanup()
{
	map.clear();
}

std::unordered_map<GLuint, tilestruct> & TileCompManager::getMap()
{
	return map;
}

