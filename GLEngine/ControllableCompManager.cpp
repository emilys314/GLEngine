#include "ControllableCompManager.h"


void ControllableCompManager::set(GLuint ID, GLuint energy)
{
	map[ID] = energy;
}

void ControllableCompManager::remove(GLuint ID)
{
	map.erase(ID);
}

std::unordered_map<GLuint, GLuint> & ControllableCompManager::getMap()
{
	return map;
}
