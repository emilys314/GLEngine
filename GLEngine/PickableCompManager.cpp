#include "PickableCompManager.h"



void PickableCompManager::set(GLuint ID, GLuint type)
{
	map[ID] = type;

}

void PickableCompManager::remove(GLuint ID)
{
	map.erase(ID);
}

std::unordered_map<GLuint, GLuint> & PickableCompManager::getMap()
{
	return map;
}
