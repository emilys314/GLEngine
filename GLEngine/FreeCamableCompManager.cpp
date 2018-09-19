#include "FreeCamableCompManager.h"


void FreeCamableCompManager::set(GLuint ID, GLuint innerID)
{
	map[ID] = innerID;
}

void FreeCamableCompManager::remove(GLuint ID)
{
	map.erase(ID);
}

std::unordered_map<GLuint, GLuint> & FreeCamableCompManager::getMap()
{
	return map;
}
