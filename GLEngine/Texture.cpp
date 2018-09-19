#include "Texture.h"

Texture::Texture()
{

}

Texture::Texture(GLuint ID)
{
	textureID = ID;
}

GLuint Texture::getTextureID()
{
	return textureID;
}