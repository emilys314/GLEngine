#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>

class TextureCompManager
{
public:
	static TextureCompManager & getInstance()
	{
		static TextureCompManager instance; // Guaranteed to be destroyed.
											 // Instantiated on first use.
		return instance;
	}
	TextureCompManager(TextureCompManager const&) = delete;
	void operator=(TextureCompManager const&) = delete;

	void set(GLuint, GLuint);
	void remove(GLuint);
	void cleanup();
	std::unordered_map<GLuint, GLuint> & getMap();
private:
	TextureCompManager() {}
	std::unordered_map<GLuint, GLuint> map;
};

