#pragma once

#define GLEW_STATIC
#include <unordered_map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath> 

#include "EntityManager.h"
#include "StaminaCompManager.h"
#include "EntityManager.h"
#include "PositionCompManager.h"
#include "ModelCompManager.h"
#include "TextureCompManager.h"	
#include "Loader.h"
#include "RawModel.h"

struct tilestruct
{
	GLuint tileentityID;
	glm::vec3 tileposition;
	glm::vec3 parentposition;
	GLfloat distfromparent;
	GLfloat distfrombase;
	bool isouterlayer;
};

class GridMovementSystem
{
public:
	void update(GLfloat &, int &, int &, std::unordered_map<GLuint, GLuint> &, std::unordered_map<GLuint, glm::vec3> &, std::unordered_map<GLuint, glm::vec3> &, glm::vec2 &, GLuint &, std::unordered_map<GLuint, staminadata> &,
		bool &);
private:
	GLfloat distancetotilesquare(glm::vec3, glm::vec2);
	void populatetilemap(glm::vec3, GLfloat, std::unordered_map<GLuint, glm::vec3> &);
	void trytocreatenewperptile(glm::vec3, glm::vec3, GLuint, GLuint, std::unordered_map<GLuint, glm::vec3> &);
	void trytocreatenewdiagtile(glm::vec3, glm::vec3, GLuint, GLuint, std::unordered_map<GLuint, glm::vec3> &);
	GLuint nexttileID = 1;
	GLuint focusEntID = -1;
	std::vector<tilestruct> movementmap;
	GLuint highlighted = Loader::getInstance().loadToTextureID("resources/highlighted.png");
	RawModel tileplane = Loader::getInstance().objToRawModel("resources/tile_plane.obj");
};

