#include "CamMountInfoSystem.h"



void CamMountInfoSystem::update(GLuint & ID, std::unordered_map<GLuint, glm::vec3> & positions, std::unordered_map<GLuint, glm::vec3> & orientations)
{
	position = positions[ID];
	orientation = orientations[ID];
}

glm::vec3 & CamMountInfoSystem::getPosition()
{
	return position;
}

glm::vec3 & CamMountInfoSystem::getOrientation()
{
	return orientation;
}