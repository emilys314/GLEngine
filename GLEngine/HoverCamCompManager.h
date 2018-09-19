#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>

class HoverCamCompManager
{
public:
	static HoverCamCompManager & getInstance()
	{
		static HoverCamCompManager instance; // Guaranteed to be destroyed.
												// Instantiated on first use.
		return instance;
	}
	HoverCamCompManager(HoverCamCompManager const&) = delete;
	void operator=(HoverCamCompManager const&) = delete;

	void set(GLuint, GLuint);
	void remove(GLuint);
	void cleanup();
	std::unordered_map<GLuint, GLuint> & getMap();
private:
	HoverCamCompManager() {};
	std::unordered_map<GLuint, GLuint> map;
};
