#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#define GLEW_STATIC

#include <GL/glew.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	// The program ID
	GLuint Program;
	Shader();
	// Constructor reads and builds the shader
	Shader(const GLchar*, const GLchar*);
	// Use the program
	void Use();
};

#endif