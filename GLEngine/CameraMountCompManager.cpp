#include "CameraMountCompManager.h"



void CameraMountCompManager::set(GLuint ID)
{
	mountID = ID;
}

void CameraMountCompManager::remove()
{
	mountID = 0;
}

void CameraMountCompManager::cleanup()
{
	mountID = 0;
}

GLuint & CameraMountCompManager::getCameraMountID()
{
	return mountID;
}
