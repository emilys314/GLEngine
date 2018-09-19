#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class CameraMountCompManager
{
public:
	static CameraMountCompManager & getInstance()
	{
		static CameraMountCompManager instance; // Guaranteed to be destroyed.
												  // Instantiated on first use.
		return instance;
	}
	CameraMountCompManager(CameraMountCompManager const&) = delete;
	void operator=(CameraMountCompManager const&) = delete;

	void set(GLuint);
	void remove();
	void cleanup();
	GLuint & getCameraMountID();
private:
	CameraMountCompManager() {}
	GLuint mountID;
};

