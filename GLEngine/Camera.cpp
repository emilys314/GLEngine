#include "Camera.h"



Camera::Camera(glm::vec3 position, glm::vec3 orientation)
{
	Camera::position = position;
	Camera::orientation = orientation;
}

void Camera::processInput(GLfloat & deltaTime, bool keys[], GLfloat xoffset, GLfloat yoffset)
{
	GLfloat movespeed = 10.0f;
	GLfloat turnspeed = 10.0f;

	orientation.x -= yoffset*0.001f;
	orientation.y += xoffset*0.001f;
	//if (orientation.x + yoffset > 89.0f)
	//	orientation.x = 89.0f;
	//if (orientation.y + xoffset > 89.0f)
	//	orientation.y = 89.0f;

	GLfloat x = -movespeed*deltaTime*glm::cos(orientation.x) * glm::sin(orientation.y);//x works when negative
	GLfloat y = movespeed*deltaTime*glm::sin(orientation.x);
	GLfloat z = movespeed*deltaTime*glm::cos(orientation.x) * glm::cos(orientation.y);

	if (keys[GLFW_KEY_W]){
		position += glm::vec3(x, y, z);
	}
	if (keys[GLFW_KEY_S]) {
		position -= glm::vec3(x, y, z);
	}
	//if (keys[GLFW_KEY_A]) {
	//	orientation -= glm::vec3(0.0f, 10.0f*deltaTime, 0.0f);
	//}
	//if (keys[GLFW_KEY_D]) {
	//	orientation += glm::vec3(0.0f, 10.0f*deltaTime, 0.0f);
	//}


}

void Camera::setPosition(glm::vec3 vector)
{
	position = vector;
}

glm::vec3 Camera::getPosition()
{
	return position;
}

void Camera::setOrientation(glm::vec3 vector)
{
	orientation = vector;
}

glm::vec3 Camera::getOrientation()
{
	return orientation;
}