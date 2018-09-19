#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>

#include "Camera.h"
#include "Shader.h"
#include "CameraMountCompManager.h"
#include "ModelCompManager.h"
#include "GuiPositionCompManager.h"
#include "RawModel.h"
#include "Loader.h"

class RenderSystem
{
public:
	RenderSystem();
	void prepare(GLuint &, GLuint &, GLfloat &, glm::vec3 &, glm::vec3 &);
	void render(std::unordered_map<GLuint, GLuint> &, std::unordered_map<GLuint, mystructure> &, std::unordered_map<GLuint, glm::vec3> &, std::unordered_map<GLuint, glm::vec3> &);
	void renderGUI(std::unordered_map<GLuint, GLuint> &, std::unordered_map<GLuint, glm::vec3> &, std::unordered_map<GLuint, glm::vec3> &, std::unordered_map<GLuint, mystructure> &);
private:
	GLfloat vertices[12] = { -0.5f,  0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, -0.5f};
	GLuint quad = Loader::getInstance().loadToVAOid(vertices, 8);
	Shader simpleShader;
	Shader GuiShader;
	glm::mat4 projectionMat, viewMat;
	glm::vec3 positionVec;

};

