#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>

struct staminadata { GLfloat basestamina, currentstamina; };

class StaminaCompManager
{
public:
	static StaminaCompManager & getInstance()
	{
		static StaminaCompManager instance; // Guaranteed to be destroyed.
										  // Instantiated on first use.
		return instance;
	}
	StaminaCompManager(StaminaCompManager const&) = delete;
	void operator=(StaminaCompManager const&) = delete;

	void set(GLuint, GLfloat, GLfloat);
	void remove(GLuint);
	void cleanup();
	std::unordered_map<GLuint, staminadata> & getMap();
private:
	StaminaCompManager() {}
	std::unordered_map<GLuint, staminadata> map;
};

