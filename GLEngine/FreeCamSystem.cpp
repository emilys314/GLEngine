#include "FreeCamSystem.h"



void FreeCamSystem::update(GLfloat & deltaTime, bool keys[], GLfloat& xoffset, GLfloat& yoffset, std::unordered_map<GLuint, GLuint> & freecams, std::unordered_map<GLuint, glm::vec3> & position,
	std::unordered_map<GLuint, glm::vec3> & orientation)
{
	GLfloat movespeed = 20.0f;
	GLfloat turnspeed = 10.0f;

	for (auto i : freecams)
	{
		GLuint key = i.first;

		//orientation[key].x -= yoffset*0.001f;
		//orientation[key].y += xoffset*0.001f;

		GLfloat x = -movespeed*deltaTime*glm::cos(orientation[key].x) * glm::sin(orientation[key].y);//x works when negative
		GLfloat y = movespeed*deltaTime*glm::sin(orientation[key].x);
		GLfloat z = movespeed*deltaTime*glm::cos(orientation[key].x) * glm::cos(orientation[key].y);


		if (keys[GLFW_KEY_UP]) {
			position[key] -= glm::vec3(x, y, z);
		}
		if (keys[GLFW_KEY_DOWN]) {
			position[key] += glm::vec3(x, y, z);
		}
	}
}
