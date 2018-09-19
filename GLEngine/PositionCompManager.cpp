#include "PositionCompManager.h"



void PositionCompManager::set(GLuint ID, glm::vec3 vector)
{
	map[ID] = vector;
}

void PositionCompManager::remove(GLuint ID)
{
	map.erase(ID);
}

void PositionCompManager::cleanup()
{
	map.clear();
}

std::unordered_map<GLuint, glm::vec3> & PositionCompManager::getMap()
{
	return map;
}
