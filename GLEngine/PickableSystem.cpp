#include "PickableSystem.h"


void PickableSystem::update(GLfloat & xoffset, GLfloat & yoffset, GLuint & width, GLuint & height, GLfloat & fov, glm::vec3 & position, glm::vec3 & orientation, std::unordered_map<GLuint, GLuint> & pickable, 
	std::unordered_map<GLuint, glm::vec3> & positions, std::unordered_map<GLuint, boxrange> & boundingboxes)
{
	glm::mat4 projection, view;

	projection = glm::perspective(fov, 1280.0f / 720.0f, 0.1f, 500.0f);

	view = glm::rotate(view, orientation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::rotate(view, orientation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	//view = glm::translate(view, -position);

	GLfloat mouseX = xoffset / (1280.0f  * 0.5f) - 1.0f;
	GLfloat mouseY = yoffset / (720.0f * 0.5f) - 1.0f;

	glm::mat4 invVP = glm::inverse(projection * view);
	glm::vec4 screenPos = glm::vec4(mouseX, -mouseY, 1.0f, 1.0f);
	glm::vec4 worldPos = invVP * screenPos;

	glm::vec3 dir = glm::normalize(glm::vec3(worldPos));

	//std::cout << dir.x << " " << dir.y << " " << dir.z << "   ";

	picked = 0;
	for (auto i : pickable)//go through each pickable entity
	{
		GLuint ID = i.first;
		boxrange currentbox = boundingboxes[ID];
		glm::vec3 boxposition = positions[ID];

		glm::vec3 raySlider = position;//make the starting position at the camera position
		GLfloat lastraySlidery = raySlider.y;


		for (GLfloat slide = 0; slide < 100; slide++)//and test along a ray to see if it intersects
		{
			bool interscectsX = false, interscectsY = false, interscectsZ = false;

			raySlider += dir*slide*0.01f;//extend the picking ray
			if ((raySlider.x > (currentbox.xMin + boxposition.x)) && (raySlider.x < (currentbox.xMax + boxposition.x))) { interscectsX = true; }
			if ((raySlider.y > (currentbox.yMin + boxposition.y)) && (raySlider.y < (currentbox.yMax + boxposition.y))) { interscectsY = true; }
			if ((raySlider.z > (currentbox.zMin + boxposition.z)) && (raySlider.z < (currentbox.zMax + boxposition.z))) { interscectsZ = true; }
			if ((interscectsX == true) && (interscectsY == true) && (interscectsZ == true))
			{
				//std::cout << picked << " PICKED\n";
				picked = ID;
			}


			if (raySlider.y < 0 && lastraySlidery >= 0)//select which grid is being pointed at
			{
				gridPicked = glm::vec2(raySlider.x, raySlider.z);
			}
			lastraySlidery = raySlider.y;
		}
	}

	GLfloat tempx = gridPicked.x / 2;//round the grid picked stuff
	GLfloat tempy = gridPicked.y / 2;
	gridPicked.x = round(tempx) * 2;
	gridPicked.y = round(tempy) * 2;

	//std::cout << "GRID " << gridPicked.x << "  " << gridPicked.y << "\n";

	//std::cout << picked << "\n";
}

GLuint & PickableSystem::getPicked()
{
	return picked;
}

glm::vec2 & PickableSystem::getGridPicked()
{
	return gridPicked;
}