#include "GridCompManager.h"


void GridCompManager::add(GLuint ID, glm::vec2 position)
{
	map[ID] = position;
}

void GridCompManager::remove(GLuint ID)
{
	map.erase(ID);
}

std::unordered_map<GLuint, glm::vec2> & GridCompManager::getMap()
{
	return map;
}