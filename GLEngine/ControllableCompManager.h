#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>

class ControllableCompManager
{
public:
	static ControllableCompManager & getInstance()
	{
		static ControllableCompManager instance; // Guaranteed to be destroyed.
												// Instantiated on first use.
		return instance;
	}
	ControllableCompManager(ControllableCompManager const&) = delete;
	void operator=(ControllableCompManager const&) = delete;

	void set(GLuint, GLuint);
	void remove(GLuint);
	std::unordered_map<GLuint, GLuint> & getMap();
private:
	ControllableCompManager() {}
	std::unordered_map<GLuint, GLuint> map;
};

