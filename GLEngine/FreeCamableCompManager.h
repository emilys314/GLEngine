#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>

class FreeCamableCompManager
{
public:
	static FreeCamableCompManager & getInstance()
	{
		static FreeCamableCompManager instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}
	FreeCamableCompManager(FreeCamableCompManager const&) = delete;
	void operator=(FreeCamableCompManager const&) = delete;

	void set(GLuint, GLuint);
	void remove(GLuint);
	std::unordered_map<GLuint, GLuint> & getMap();
private:
	FreeCamableCompManager() {};
	std::unordered_map<GLuint, GLuint> map;
};
