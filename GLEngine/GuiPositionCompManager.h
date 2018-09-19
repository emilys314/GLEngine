#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>

class GuiPositionCompManager
{
public:
	static GuiPositionCompManager & getInstance()
	{
		static GuiPositionCompManager instance; // Guaranteed to be destroyed.
											 // Instantiated on first use.
		return instance;
	}
	GuiPositionCompManager(GuiPositionCompManager const&) = delete;
	void operator=(GuiPositionCompManager const&) = delete;

	void set(GLuint, glm::vec3);
	void remove(GLuint);
	void cleanup();
	std::unordered_map<GLuint, glm::vec3> & getMap();
private:
	GuiPositionCompManager() {}
	std::unordered_map<GLuint, glm::vec3> map;
};

