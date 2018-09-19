#define GLEW_STATIC

#include <iostream>

#include "GameEngine.h"
#include "IntroState.h"
#include "GamingState.h"

//create callback functions for inputs
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

GameEngine game;//create game object that has basically everything

int main()
{

	// initialize the engine
	game.Init();

	glfwSetKeyCallback(game.display.window, key_callback);
	glfwSetCursorPosCallback(game.display.window, mouse_callback);
	glfwSetMouseButtonCallback(game.display.window, mouse_button_callback);

	// load the intro
	game.ChangeState(IntroState::getInstance());

	// main loop
	while (game.Running())
	{
		game.HandleEvents();
		game.Update();
		game.Draw();
	}

	// cleanup the engine
	game.Cleanup();        

	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	//cout << key << endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			game.keysHeld[key] = true;
			game.keyPressed = key;
		}
		else if (action == GLFW_RELEASE)
			game.keysHeld[key] = false;
	}
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (game.firstMouse)
	{
		game.xpos = xpos;
		game.ypos = ypos;
		game.firstMouse = false;
	}

	game.xoffset = xpos - game.xpos;
	game.yoffset = game.ypos - ypos;  // Reversed since y-coordinates go from bottom to left

	game.xpos = xpos;
	game.ypos = ypos;
}


void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		game.mouseButtonHeld = button;
		game.mouseButtonPressed = button;
	}
	else if (action == GLFW_RELEASE)
		game.mouseButtonHeld = -1;
}