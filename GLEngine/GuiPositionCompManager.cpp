#include "GuiPositionCompManager.h"



void GuiPositionCompManager::set(GLuint ID, glm::vec3 vector)
{
	map[ID] = vector;
}

void GuiPositionCompManager::remove(GLuint ID)
{
	map.erase(ID);
}

void GuiPositionCompManager::cleanup()
{
	map.clear();
}

std::unordered_map<GLuint, glm::vec3> & GuiPositionCompManager::getMap()
{
	return map;
}
