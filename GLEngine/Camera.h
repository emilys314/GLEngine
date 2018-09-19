#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
	Camera(glm::vec3, glm::vec3);
	void processInput(GLfloat&, bool[], GLfloat, GLfloat);
	void setPosition(glm::vec3);
	glm::vec3 getPosition();
	void setOrientation(glm::vec3);
	glm::vec3 getOrientation();
private:
	glm::vec3 position;
	glm::vec3 orientation;
};

