#include "NameCompManager.h"


void NameCompManager::addName(GLuint ID, std::string text)
{
	map[ID] = text;
}

void NameCompManager::removeName(GLuint ID)
{
	map.erase(ID);
}

std::unordered_map<GLuint, std::string> & NameCompManager::getMap()
{
	return map;
}