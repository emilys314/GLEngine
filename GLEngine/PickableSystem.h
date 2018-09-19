#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <unordered_map>
#include <iostream>
#include <math.h>

#include "AABoundingBoxCompManager.h"

class PickableSystem
{
public:
	void update(GLfloat &, GLfloat &, GLuint &, GLuint &, GLfloat &, glm::vec3 &, glm::vec3 &, std::unordered_map<GLuint, GLuint> &, std::unordered_map<GLuint, glm::vec3> &, std::unordered_map<GLuint, boxrange> &);
	GLuint & getPicked();
	glm::vec2 & getGridPicked();
private:
	GLuint picked = 0;
	glm::vec2 gridPicked = glm::vec2(0.0f, 0.0f);
};

