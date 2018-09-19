#include "ModelCompManager.h"



void ModelCompManager::set(GLuint ID, GLuint VAOid, GLuint verticeNumber)
{
	mystructure newstruct;
	newstruct.VAOid = VAOid;
	newstruct.verticeCount = verticeNumber;
	map[ID] = newstruct;
}

void ModelCompManager::remove(GLuint ID)
{
	map.erase(ID);
}

void ModelCompManager::cleanup()
{
	map.clear();
}

std::unordered_map<GLuint, mystructure> & ModelCompManager::getMap()
{
	return map;
}

