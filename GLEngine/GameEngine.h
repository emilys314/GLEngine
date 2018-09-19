#ifndef GAMEENGINE_H
#define GAMEENGINE_H

class GameState;

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "DisplayManager.h"
#include "Loader.h"


class GameEngine
{
public:
	void Init();
	void Cleanup();

	void ChangeState(GameState * state);
	void PushState(GameState * state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return !glfwWindowShouldClose(display.window); }
	void Quit() { glfwSetWindowShouldClose(display.window, GL_TRUE); }


	DisplayManager display = DisplayManager(1280, 720);

	GLuint width = 1280;
	GLuint height = 720;
	GLfloat fov = 70;

	GLfloat xoffset = 0, yoffset = 0;
	GLfloat xpos = 0, ypos = 0;

	bool keysHeld[1024] ;
	int keyPressed;
	int mouseButtonHeld = -1;
	int mouseButtonPressed = -1;

	bool firstMouse = true;

	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

private:
	// the stack of states
	std::vector<GameState*> states;

};

#endif 
