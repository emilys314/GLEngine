#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>

class GridCollisionCompManager
{
public:
	static GridCollisionCompManager & getInstance()
	{
		static GridCollisionCompManager instance; // Guaranteed to be destroyed.
										 // Instantiated on first use.
		return instance;
	}
	GridCollisionCompManager(GridCollisionCompManager const&) = delete;
	void operator=(GridCollisionCompManager const&) = delete;

	void set(GLuint, glm::vec3);
	void remove(GLuint);
	std::unordered_map<GLuint, glm::vec3> & getMap();
private:
	GridCollisionCompManager() {}
	std::unordered_map<GLuint, glm::vec3> map;
};