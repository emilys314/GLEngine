#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>

class ScaleCompManager
{
public:
	static ScaleCompManager & getInstance()
	{
		static ScaleCompManager instance; // Guaranteed to be destroyed.
												// Instantiated on first use.
		return instance;
	}
	ScaleCompManager(ScaleCompManager const&) = delete;
	void operator=(ScaleCompManager const&) = delete;

	void set(GLuint, glm::vec3);
	void remove(GLuint);
	void cleanup();
	std::unordered_map<GLuint, glm::vec3> & getMap();
private:
	ScaleCompManager() {}
	std::unordered_map<GLuint, glm::vec3> map;
};

