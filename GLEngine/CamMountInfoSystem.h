#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>

class CamMountInfoSystem
{
public:
	void update(GLuint &, std::unordered_map<GLuint, glm::vec3> &, std::unordered_map<GLuint, glm::vec3> &);
	glm::vec3 & getPosition();
	glm::vec3 & getOrientation();
private:
	glm::vec3 position;
	glm::vec3 orientation;
};

