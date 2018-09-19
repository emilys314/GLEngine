#include "TextureCompManager.h"


void TextureCompManager::set(GLuint ID, GLuint textureID)
{
	map[ID] = textureID;
}

void TextureCompManager::remove(GLuint ID)
{
	map.erase(ID);
}

void TextureCompManager::cleanup()
{
	map.clear();
}

std::unordered_map<GLuint, GLuint> & TextureCompManager::getMap()
{
	return map;
}
