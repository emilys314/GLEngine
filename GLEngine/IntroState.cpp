
#include <stdio.h>

#include "gameengine.h"
#include "gamestate.h"
#include "IntroState.h"
#include "GamingState.h"

//IntroState IntroState::m_IntroState;

void IntroState::Init(GameEngine * game)
{
	GLuint mainmenu = Loader::getInstance().loadToTextureID("resources/mainmenu.png");

	GLuint testgui = EntityManager::getInstance().createEntity();
	GuiPositionCompManager::getInstance().set(testgui, glm::vec3(0.0, 0.0, 0.0));
	TextureCompManager::getInstance().set(testgui, mainmenu);
	ScaleCompManager::getInstance().set(testgui, glm::vec3(2.0, 2.0, 2.0));

	GLuint camMount = EntityManager::getInstance().createEntity();
	PositionCompManager::getInstance().set(camMount, glm::vec3(0.0f, 0.0f, 18.0f));
	CameraMountCompManager::getInstance().set(camMount);

	printf("State: IntroState Init\n");
}

void IntroState::Cleanup(GameEngine * game)
{
	EntityManager::getInstance().cleanup();
	PositionCompManager::getInstance().cleanup();
	OrientationCompManager::getInstance().cleanup();
	ModelCompManager::getInstance().cleanup();
	TextureCompManager::getInstance().cleanup();
	CameraMountCompManager::getInstance().cleanup();
	GuiPositionCompManager::getInstance().cleanup();
	ScaleCompManager::getInstance().cleanup();

	printf("State: IntroState Cleanup\n");
}

void IntroState::Pause()
{
	printf("State: IntroState Pause\n");
}

void IntroState::Resume()
{
	printf("State: IntroState Resume\n");
}

void IntroState::HandleEvents(GameEngine* game)
{
	if (game->keyPressed > 0)
	{
		Loader::getInstance().flush();
		game->ChangeState(GamingState::getInstance());
	}
}

void IntroState::Update(GameEngine* game)
{
	//FreeCamS.update(game->deltaTime, game->keysHeld, game->xoffset, game->yoffset, FreeCamableCompManager::getInstance().getMap(), PositionCompManager::getInstance().getMap(), OrientationCompManager::getInstance().getMap());//update flying position from keys
	CamMountInfoS.update(CameraMountCompManager::getInstance().getCameraMountID(), PositionCompManager::getInstance().getMap(), OrientationCompManager::getInstance().getMap());//update cameramount position(not sure what the point of camMountInfoS is)
	//PickableS.update(game->xpos, game->ypos, game->width, game->height, game->fov, CamMountInfoS.getPosition(), CamMountInfoS.getOrientation(), PickableCompManager::getInstance().getMap(), PositionCompManager::getInstance().getMap(), AABoundingBoxCompManager::getInstance().getMap());
	//GridMovementS.update(game->deltaTime, game->keyPressed, game->mouseButtonPressed, ControllableCompManager::getInstance().getMap(), PositionCompManager::getInstance().getMap(), GridCollisionCompManager::getInstance().getMap(), PickableS.getGridPicked(), PickableS.getPicked());

	RenderS.prepare(game->width, game->height, game->fov, CamMountInfoS.getPosition(), CamMountInfoS.getOrientation());
	RenderS.render(TextureCompManager::getInstance().getMap(), ModelCompManager::getInstance().getMap(), PositionCompManager::getInstance().getMap(), OrientationCompManager::getInstance().getMap());
	RenderS.renderGUI(TextureCompManager::getInstance().getMap(), GuiPositionCompManager::getInstance().getMap(), ScaleCompManager::getInstance().getMap(), ModelCompManager::getInstance().getMap());

	//printf("CIntroState Update\n");
}

void IntroState::Draw(GameEngine* game)
{
	glfwSwapBuffers(game->display.window);//draw the frame 
										  //printf("CIntroState Draw\n");
}
