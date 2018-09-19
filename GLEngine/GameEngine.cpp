#include "GameEngine.h"

#include "gamestate.h"



void GameEngine::Init()
{

	printf("CGameEngine Init\n");
}

void GameEngine::Cleanup()
{
	// cleanup the all states
	while (!states.empty()) {
		//states.back().Cleanup();
		states.pop_back();
	}

	printf("GameEngine Cleanup\n");

	Loader::getInstance().flush();

	glfwTerminate();

	// shutdown SDL
}

void GameEngine::ChangeState(GameState * state)
{
	// cleanup the current state
	if (!states.empty()) {
		states.back()->Cleanup(this);
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init(this);
}

void GameEngine::PushState(GameState* state)
{
	// pause current state
	if (!states.empty()) {
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init(this);
}

void GameEngine::PopState()
{
	// cleanup the current state
	if (!states.empty()) {
		states.back()->Cleanup(this);
		states.pop_back();
	}

	// resume previous state
	if (!states.empty()) {
		states.back()->Resume();
	}
}


void GameEngine::HandleEvents()
{
	GLfloat currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
	xoffset = 0;
	yoffset = 0;
	keyPressed = -1;
	mouseButtonPressed = -1;

	glfwPollEvents();
	// let the state handle events
	states.back()->HandleEvents(this);
}

void GameEngine::Update()
{
	// let the state update the game
	states.back()->Update(this);
}

void GameEngine::Draw()
{
	// let the state draw the screen
	states.back()->Draw(this);
}


