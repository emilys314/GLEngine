#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>

struct boxrange { GLfloat xMin, xMax, yMin, yMax, zMin, zMax; };

class AABoundingBoxCompManager
{
public:
	static AABoundingBoxCompManager & getInstance()
	{
		static AABoundingBoxCompManager instance; // Guaranteed to be destroyed.
												// Instantiated on first use.
		return instance;
	}
	AABoundingBoxCompManager(AABoundingBoxCompManager const&) = delete;
	void operator=(AABoundingBoxCompManager const&) = delete;

	void set(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void remove(GLuint);
	std::unordered_map<GLuint, boxrange> & getMap();
private:
	AABoundingBoxCompManager() {}
	std::unordered_map<GLuint, boxrange> map;
};

