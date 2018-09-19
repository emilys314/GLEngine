#include "GridCollisionCompManager.h"



void GridCollisionCompManager::set(GLuint ID, glm::vec3 gridPosition)
{
	map[ID] = gridPosition;
}

void GridCollisionCompManager::remove(GLuint ID)
{
	map.erase(ID);
}

std::unordered_map<GLuint, glm::vec3> & GridCollisionCompManager::getMap()
{
	return map;
}
