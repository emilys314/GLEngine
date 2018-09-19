#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>

class PositionCompManager
{
public:
	static PositionCompManager & getInstance()
	{
		static PositionCompManager instance; // Guaranteed to be destroyed.
											 // Instantiated on first use.
		return instance;
	}
	PositionCompManager(PositionCompManager const&) = delete;
	void operator=(PositionCompManager const&) = delete;

	void set(GLuint, glm::vec3);
	void remove(GLuint);
	void cleanup();
	std::unordered_map<GLuint, glm::vec3> & getMap();
private:
	PositionCompManager() {}
	std::unordered_map<GLuint, glm::vec3> map;
};

