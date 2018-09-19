#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "RawModel.h"
#include "Texture.h"

class TexturedModel
{
public:
	TexturedModel();
	TexturedModel(RawModel, Texture, glm::vec3);
	void scale(glm::vec3);
	void rotate(glm::vec3);
	glm::vec3 getRotation();
	void translate(glm::vec3);
	GLuint getRawModelID();
	GLuint getTextureID();
	glm::mat4 getTransMatrix();
private:
	RawModel rawModel;
	Texture texture;
	glm::vec3 scaling;
	glm::vec3 rotation;
	glm::vec3 position;
	//glm::mat4 transMatrix;
};

