#include "AABoundingBoxCompManager.h"



void AABoundingBoxCompManager::set(GLuint ID, GLfloat xMin, GLfloat xMax, GLfloat yMin, GLfloat yMax, GLfloat zMin, GLfloat zMax)
{
	boxrange newstruct;
	newstruct.xMin = xMin;
	newstruct.xMax = xMax;
	newstruct.yMin = yMin;
	newstruct.yMax = yMax;
	newstruct.zMin = zMin;
	newstruct.zMax = zMax;
	map[ID] = newstruct;
}

void AABoundingBoxCompManager::remove(GLuint ID)
{
	map.erase(ID);
}

std::unordered_map<GLuint, boxrange> & AABoundingBoxCompManager::getMap()
{
	return map;
}
