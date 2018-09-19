#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>

struct mystructure { GLuint VAOid, verticeCount; };

class ModelCompManager
{
public:
	static ModelCompManager & getInstance()
	{
		static ModelCompManager instance; // Guaranteed to be destroyed.
										  // Instantiated on first use.
		return instance;
	}
	ModelCompManager(ModelCompManager const&) = delete;
	void operator=(ModelCompManager const&) = delete;

	void set(GLuint, GLuint, GLuint);
	void remove(GLuint);
	void cleanup();
	std::unordered_map<GLuint, mystructure> & getMap();
private:
	ModelCompManager() {}
	std::unordered_map<GLuint, mystructure> map;
};

