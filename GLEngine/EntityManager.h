#pragma once

#include <GL/glew.h>

#include <vector>
#include <string>
#include <iostream>

#include <unordered_map>

class EntityManager
{
public:
	static EntityManager & getInstance()
	{
		static EntityManager instance; // Guaranteed to be destroyed.
											// Instantiated on first use.
		return instance;
	}
	EntityManager(EntityManager const&) = delete;
	void operator=(EntityManager const&) = delete;
	
	GLuint createEntity();
	void destroyEntity(GLuint);
	void cleanup();
	void printIDs();
private:
	EntityManager() {}
	std::unordered_map<GLuint, GLuint> currentIDs;
	std::unordered_map<GLuint, GLuint> deletedIDs;
	GLuint nextID = 1;
};

