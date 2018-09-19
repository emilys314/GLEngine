#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>
#include <unordered_map>

class LightCompManager
{
public:
	static LightCompManager & getInstance()
	{
		static LightCompManager instance; // Guaranteed to be destroyed.
												  // Instantiated on first use.
		return instance;
	}
	LightCompManager(LightCompManager const&) = delete;
	void operator=(LightCompManager const&) = delete;

	void add(GLuint, glm::vec3);
	void remove(GLuint);
	std::unordered_map<GLuint, glm::vec3> & getMap();
private:
	LightCompManager() {}
	std::unordered_map<GLuint, glm::vec3> map;
};

