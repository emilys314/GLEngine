#include "TexturedModel.h"

TexturedModel::TexturedModel()
{

}

TexturedModel::TexturedModel(RawModel rawModel, Texture texture, glm::vec3 position)
{
	TexturedModel::rawModel = rawModel;
	TexturedModel::texture = texture;
	TexturedModel::position = position;

	scaling = glm::vec3(1.0f, 1.0f, 1.0f);
	//TexturedModel::transMatrix = transMatrix;
}

void TexturedModel::scale(glm::vec3 transformation)
{
	scaling = transformation;
}

void TexturedModel::rotate(glm::vec3 angles)
{
	rotation += angles;
}

glm::vec3 TexturedModel::getRotation()
{
	return rotation;
}

void TexturedModel::translate(glm::vec3 transformation)
{
	position += transformation;
}

GLuint TexturedModel::getRawModelID()
{
	return rawModel.getVAOid();
}

GLuint TexturedModel::getTextureID()
{
	return texture.getTextureID();
}

glm::mat4 TexturedModel::getTransMatrix()
{
	glm::mat4 transMatrix;
	transMatrix = glm::scale(transMatrix, scaling);
	//std::cout << "X: " << rotation.x << " Y: " << rotation.y << " Z: " << rotation.z << "\n";
	transMatrix = glm::rotate(transMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	transMatrix = glm::rotate(transMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	transMatrix = glm::rotate(transMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	transMatrix = glm::translate(transMatrix, position);
	//glm::vec3 col1(transMatrix[0][0], transMatrix[0][1], transMatrix[0][2]);
	//std::cout << transMatrix[2][0] << " " << transMatrix[2][1] << " " << transMatrix[2][2] << "\n";
	//std::cout << "rotY: " << rotY << "\n";

	return transMatrix;
}