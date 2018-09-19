#include "LightCompManager.h"


void LightCompManager::add(GLuint ID, glm::vec3 color)
{
	map[ID] = color;
}

void LightCompManager::remove(GLuint ID)
{
	map.erase(ID);
}

std::unordered_map<GLuint, glm::vec3> & LightCompManager::getMap()
{
	return map;
}