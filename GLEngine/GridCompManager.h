#pragma once

#include <GL/glew.h>

#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

struct people { GLuint VAOid, verticeCount; };

class GridCompManager
{
public:
	static GridCompManager & getInstance()
	{
		static GridCompManager instance; // Guaranteed to be destroyed.
												 // Instantiated on first use.
		return instance;
	}
	GridCompManager(GridCompManager const&) = delete;
	void operator=(GridCompManager const&) = delete;

	void add(GLuint, glm::vec2);
	void remove(GLuint);
	std::unordered_map<GLuint, glm::vec2> & getMap();
private:
	GridCompManager() {}
	std::unordered_map<GLuint, glm::vec2> map;
};

