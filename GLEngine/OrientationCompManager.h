#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>

class OrientationCompManager
{
public:
	static OrientationCompManager & getInstance()
	{
		static OrientationCompManager instance; // Guaranteed to be destroyed.
										 // Instantiated on first use.
		return instance;
	}
	OrientationCompManager(OrientationCompManager const&) = delete;
	void operator=(OrientationCompManager const&) = delete;

	void set(GLuint, glm::vec3);
	void remove(GLuint);
	void cleanup();
	std::unordered_map<GLuint, glm::vec3> & getMap();
private:
	OrientationCompManager() {}
	std::unordered_map<GLuint, glm::vec3> map;
};
