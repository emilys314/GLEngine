#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>

struct tilestruct { 
	GLuint type, verticeCount; 
};

class TileCompManager
{
public:
	static TileCompManager & getInstance()
	{
		static TileCompManager instance; // Guaranteed to be destroyed.
										  // Instantiated on first use.
		return instance;
	}
	TileCompManager(TileCompManager const&) = delete;
	void operator=(TileCompManager const&) = delete;

	void set(GLuint, GLuint, GLuint);
	void remove(GLuint);
	void cleanup();
	std::unordered_map<GLuint, tilestruct> & getMap();
private:
	TileCompManager() {}
	std::unordered_map<GLuint, tilestruct> map;
};

