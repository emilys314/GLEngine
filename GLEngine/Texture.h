#pragma once
#include <GL/glew.h>
#define GLEW_STATIC

class Texture
{
public:
	Texture();
	Texture(GLuint);
	GLuint getTextureID();
private:
	GLuint textureID;
};

