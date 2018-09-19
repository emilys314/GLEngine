#pragma once
#include <GL/glew.h>
#define GLEW_STATIC
#include <iostream>

class RawModel
{
public:
	RawModel();
	RawModel(GLuint, GLuint);
	GLuint getVAOid();
	GLuint getVertCount();
private:
	GLuint VAOid;
	GLuint verticeCount;

};

