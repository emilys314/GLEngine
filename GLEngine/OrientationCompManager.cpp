#include "OrientationCompManager.h"


void OrientationCompManager::set(GLuint ID, glm::vec3 vector)
{
	map[ID] = vector;
}

void OrientationCompManager::remove(GLuint ID)
{
	map.erase(ID);
}

void OrientationCompManager::cleanup()
{
	map.clear();
}
std::unordered_map<GLuint, glm::vec3> & OrientationCompManager::getMap()
{
	return map;
}
