#include "HoverCamSystem.h"


void HoverCamSystem::update(GLfloat& deltaTime, bool keysHeld[] , GLfloat & xoffset, GLfloat & yoffset, std::unordered_map<GLuint, GLuint> & hoverCams, std::unordered_map<GLuint, glm::vec3> & positions)
{
	for (auto i : hoverCams)
	{
		GLuint ID = i.first;

		if (keysHeld[GLFW_KEY_UP])
		{
			positions[ID] += glm::vec3(0.0f, 0.0f, (-20.0f)*deltaTime);
		}
		if (keysHeld[GLFW_KEY_DOWN])
		{
			positions[ID] += glm::vec3(0.0f, 0.0f, (20.0f)*deltaTime);
		}
		if (keysHeld[GLFW_KEY_LEFT])
		{
			positions[ID] += glm::vec3((-20.0f)*deltaTime, 0.0f, 0.0f);
		}
		if (keysHeld[GLFW_KEY_RIGHT])
		{
			positions[ID] += glm::vec3((20.0f)*deltaTime, 0.0f, 0.0f);
		}
	}
}