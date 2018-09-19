
#include <stdio.h>

#include "gameengine.h"
#include "gamestate.h"
#include "GamingState.h"

//IntroState IntroState::m_IntroState;

void GamingState::Init(GameEngine * game)
{
	RawModel cube = Loader::getInstance().objToRawModel("resources/test_cube.obj");
	RawModel egg = Loader::getInstance().objToRawModel("resources/egg.obj");
	RawModel test_plane = Loader::getInstance().objToRawModel("resources/test_plane.obj");
	RawModel sphere2 = Loader::getInstance().objToRawModel("resources/sphere2.obj");
	RawModel person = Loader::getInstance().objToRawModel("resources/person.obj");
	//GLuint dragon = loader.objToVAOid("resources/dragon.obj");
	//GLuint model1 = loader.loadToVAOid(vertices, sizeof(vertices));
	//GLuint model2 = loader.loadToVAOid(vertices2, sizeof(vertices2), indices2, sizeof(indices2));
	//GLuint model3 = loader.loadToVAOid(vertices3, sizeof(vertices3), uvcoords2, sizeof(uvcoords2), indices2, sizeof(indices2));
	RawModel sphere = Loader::getInstance().objToRawModel("resources/test_sphere.obj");

	GLuint texture1 = Loader::getInstance().loadToTextureID("resources/dood.png");
	GLuint texture2 = Loader::getInstance().loadToTextureID("resources/dude.png");
	GLuint texture3 = Loader::getInstance().loadToTextureID("resources/face.png");
	GLuint texture4 = Loader::getInstance().loadToTextureID("resources/green-grey.png");
	GLuint gold = Loader::getInstance().loadToTextureID("resources/gold.png");
	GLuint white = Loader::getInstance().loadToTextureID("resources/white.png");
	GLuint checkered = Loader::getInstance().loadToTextureID("resources/checkered.png");
	GLuint grid = Loader::getInstance().loadToTextureID("resources/grid.png");

	//TexturedModel texturedModel1 = TexturedModel(model1, texture1, glm::vec3(0.0f, 0.0f, 0.0f));

	GLuint floor = EntityManager::getInstance().createEntity();
	PositionCompManager::getInstance().set(floor, glm::vec3(0.0f, 0.0f, 0.0f));
	ModelCompManager::getInstance().set(floor, test_plane.getVAOid(), test_plane.getVertCount());
	TextureCompManager::getInstance().set(floor, grid);

	GLuint person1 = EntityManager::getInstance().createEntity();
	PositionCompManager::getInstance().set(person1, glm::vec3(0.0f, 1.5f, 0.0f));
	ModelCompManager::getInstance().set(person1, person.getVAOid(), person.getVertCount());
	TextureCompManager::getInstance().set(person1, texture4);
	ControllableCompManager::getInstance().set(person1, 1);
	GridCollisionCompManager::getInstance().set(person1, glm::vec3(0, 0, 0));
	PickableCompManager::getInstance().set(person1, 1);
	AABoundingBoxCompManager::getInstance().set(person1, -0.75f, 0.75f, -1.5f, 1.5f, -0.75f, 0.75f);
	StaminaCompManager::getInstance().set(person1, 6.0f, 6.0f);

	GLuint person3 = EntityManager::getInstance().createEntity();
	PositionCompManager::getInstance().set(person3, glm::vec3(-12.0f, 1.5f, 0.0f));
	ModelCompManager::getInstance().set(person3, person.getVAOid(), person.getVertCount());
	TextureCompManager::getInstance().set(person3, texture4);
	ControllableCompManager::getInstance().set(person3, 3);
	GridCollisionCompManager::getInstance().set(person3, glm::vec3(-12, 0, 0));
	PickableCompManager::getInstance().set(person3, 1);
	AABoundingBoxCompManager::getInstance().set(person3, -0.75f, 0.75f, -1.5f, 1.5f, -0.75f, 0.75f);
	StaminaCompManager::getInstance().set(person3, 6.0f, 6.0f);

	GLuint person4 = EntityManager::getInstance().createEntity();
	PositionCompManager::getInstance().set(person4, glm::vec3(14.0f, 1.5f, 4.0f));
	ModelCompManager::getInstance().set(person4, person.getVAOid(), person.getVertCount());
	TextureCompManager::getInstance().set(person4, checkered);
	ControllableCompManager::getInstance().set(person4, 4);
	GridCollisionCompManager::getInstance().set(person4, glm::vec3(14, 0, 4));
	PickableCompManager::getInstance().set(person4, 1);
	AABoundingBoxCompManager::getInstance().set(person4, -0.75f, 0.75f, -1.5f, 1.5f, -0.75f, 0.75f);
	StaminaCompManager::getInstance().set(person4, 6.0f, 6.0);

	GLuint person2 = EntityManager::getInstance().createEntity();
	PositionCompManager::getInstance().set(person2, glm::vec3(-14.0f, 1.5f, -16.0f));
	ModelCompManager::getInstance().set(person2, person.getVAOid(), person.getVertCount());
	TextureCompManager::getInstance().set(person2, texture2);
	ControllableCompManager::getInstance().set(person2, 2);
	GridCollisionCompManager::getInstance().set(person2, glm::vec3(-14, 0, -16));
	PickableCompManager::getInstance().set(person2, 1);
	AABoundingBoxCompManager::getInstance().set(person2, -0.75f, 0.75f, -1.5f, 1.5f, -0.75f, 0.75f);
	StaminaCompManager::getInstance().set(person2, 6.0f, 6.0f);

	GLuint camMount = EntityManager::getInstance().createEntity();
	PositionCompManager::getInstance().set(camMount, glm::vec3(0.0f, 15.0f, 12.0f));
	//FreeCamableCompManager::getInstance().set(camMount, camMount);
	HoverCamCompManager::getInstance().set(camMount, camMount);
	OrientationCompManager::getInstance().set(camMount, glm::vec3(1.0f, 0.0f, 0.0f));
	CameraMountCompManager::getInstance().set(camMount);

	GLuint testgui = EntityManager::getInstance().createEntity();
	GuiPositionCompManager::getInstance().set(testgui, glm::vec3(0.5, 0.5, 0.0));
	TextureCompManager::getInstance().set(testgui, texture2);
	ScaleCompManager::getInstance().set(testgui, glm::vec3(1.0, 1.0, 1.0));

	GLuint testgui2 = EntityManager::getInstance().createEntity();
	GuiPositionCompManager::getInstance().set(testgui2, glm::vec3(0.0, 0.0, 0.0));
	TextureCompManager::getInstance().set(testgui2, texture2);
	ScaleCompManager::getInstance().set(testgui2, glm::vec3(1.0, 1.0, 1.0));

	printf("CIntroState Init\n");
}

void GamingState::Cleanup(GameEngine * game)
{
	printf("CIntroState Cleanup\n");
}

void GamingState::Pause()
{
	printf("CIntroState Pause\n");
}

void GamingState::Resume()
{
	printf("CIntroState Resume\n");
}

void GamingState::HandleEvents(GameEngine* game)
{
	//printf("CIntroState HandleEvents\n");
}

void GamingState::Update(GameEngine* game)
{
	TurnBasedS.update(game->keyPressed);
	//FreeCamS.update(game->deltaTime, game->keysHeld, game->xoffset, game->yoffset, FreeCamableCompManager::getInstance().getMap(), PositionCompManager::getInstance().getMap(), OrientationCompManager::getInstance().getMap());//update flying position from keys
	HoverCamS.update(game->deltaTime, game->keysHeld, game->xoffset, game->yoffset, HoverCamCompManager::getInstance().getMap(), PositionCompManager::getInstance().getMap());
	CamMountInfoS.update(CameraMountCompManager::getInstance().getCameraMountID(), PositionCompManager::getInstance().getMap(), OrientationCompManager::getInstance().getMap());//update cameramount position(not sure what the point of camMountInfoS is)
	PickableS.update(game->xpos, game->ypos, game->width, game->height, game->fov, CamMountInfoS.getPosition(), CamMountInfoS.getOrientation(), PickableCompManager::getInstance().getMap(), 
		PositionCompManager::getInstance().getMap(), AABoundingBoxCompManager::getInstance().getMap());
	GridMovementS.update(game->deltaTime, game->keyPressed, game->mouseButtonPressed, ControllableCompManager::getInstance().getMap(), PositionCompManager::getInstance().getMap(),
		GridCollisionCompManager::getInstance().getMap(), PickableS.getGridPicked(), PickableS.getPicked(), StaminaCompManager::getInstance().getMap(), TurnBasedS.getEndTurn());


	//printf("CIntroState Update\n");
}

void GamingState::Draw(GameEngine* game)
{
	RenderS.prepare(game->width, game->height, game->fov, CamMountInfoS.getPosition(), CamMountInfoS.getOrientation());
	RenderS.render(TextureCompManager::getInstance().getMap(), ModelCompManager::getInstance().getMap(), PositionCompManager::getInstance().getMap(), OrientationCompManager::getInstance().getMap());
	RenderS.renderGUI(TextureCompManager::getInstance().getMap(), GuiPositionCompManager::getInstance().getMap(), ScaleCompManager::getInstance().getMap(), ModelCompManager::getInstance().getMap());

	glfwSwapBuffers(game->display.window);//draw the frame 
	//printf("CIntroState Draw\n");
}
