#pragma once

#include <GL/glew.h>

#include <string>
#include <unordered_map>

class NameCompManager
{
public:
	static NameCompManager & getInstance()
	{
		static NameCompManager instance; // Guaranteed to be destroyed.
										  // Instantiated on first use.
		return instance;
	}
	NameCompManager(NameCompManager const&) = delete;
	void operator=(NameCompManager const&) = delete;

	void addName(GLuint, std::string);
	void removeName(GLuint);
	std::unordered_map<GLuint, std::string> & getMap();
private:
	NameCompManager() {}
	std::unordered_map<GLuint, std::string> map;
};

