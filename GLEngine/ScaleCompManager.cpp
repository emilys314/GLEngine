#include "ScaleCompManager.h"



void ScaleCompManager::set(GLuint ID, glm::vec3 vector)
{
	map[ID] = vector;
}

void ScaleCompManager::remove(GLuint ID)
{
	map.erase(ID);
}

void ScaleCompManager::cleanup()
{
	map.clear();
}

std::unordered_map<GLuint, glm::vec3> & ScaleCompManager::getMap()
{
	return map;
}
