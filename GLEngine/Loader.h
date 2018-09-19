#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include <glm/glm.hpp>

#include "RawModel.h"
#include "iostream"
#include "Texture.h"
#include <vector>
#include <unordered_map>
#include <string>

class Loader
{
public:
	static Loader & getInstance()
	{
		static Loader instance; // Guaranteed to be destroyed.
										  // Instantiated on first use.
		return instance;
	}
	Loader(Loader const&) = delete;
	void operator=(Loader const&) = delete;

	RawModel objToRawModel(const char *);
	GLuint loadToVAOid(GLfloat vertices[], GLuint);
	GLuint loadToVAOid(GLfloat vertices[], GLuint, GLfloat indices[], GLuint);
	GLuint loadToVAOid(GLfloat vertices[], GLuint, GLfloat uvcoords[], GLuint, GLuint indices[], GLuint);
	GLuint loadToTextureID(std::string);
	void flush();
private:
	Loader() {}
	std::vector<GLuint> vaos;
	std::vector<GLuint> vbos;
	std::vector<GLuint> ebos;
	std::vector<GLuint> textures;
	GLuint createVAO();
	GLuint createVBO(GLfloat vertices[], GLuint);
	GLuint createEBO(GLuint indices[], GLuint);
	void createVertexAttribPointer(GLuint position, GLuint size, GLuint stride, GLuint offset);
	//private void storeDataInAttribute(GLuint, GLfloat []);
};

