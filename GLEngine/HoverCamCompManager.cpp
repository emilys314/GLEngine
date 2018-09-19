#include "HoverCamCompManager.h"


void HoverCamCompManager::set(GLuint ID, GLuint innerID)
{
	map[ID] = innerID;
}

void HoverCamCompManager::remove(GLuint ID)
{
	map.erase(ID);
}

void HoverCamCompManager::cleanup()
{
	map.clear();
}

std::unordered_map<GLuint, GLuint> & HoverCamCompManager::getMap()
{
	return map;
}
