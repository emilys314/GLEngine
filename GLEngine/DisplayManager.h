#pragma once
#include <iostream>
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class DisplayManager
{
public:
	DisplayManager();
	DisplayManager(GLuint, GLuint);
	void InitializeDisplayManager(GLuint, GLuint);
	void UpdateDisplayManager();
	void DestroyDisplayManager();
	GLFWwindow* window;
private:
	int width, height;
};

