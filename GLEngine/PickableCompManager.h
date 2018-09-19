#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>

class PickableCompManager
{
public:
	static PickableCompManager & getInstance()
	{
		static PickableCompManager instance; // Guaranteed to be destroyed.
												// Instantiated on first use.
		return instance;
	}
	PickableCompManager(PickableCompManager const&) = delete;
	void operator=(PickableCompManager const&) = delete;

	void set(GLuint, GLuint);
	void remove(GLuint);
	std::unordered_map<GLuint, GLuint> & getMap();
private:
	PickableCompManager() {}
	std::unordered_map<GLuint, GLuint> map;
};