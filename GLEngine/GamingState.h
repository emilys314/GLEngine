#pragma once

#include "GameState.h"

#include "EntityManager.h"
#include "NameCompManager.h"
#include "PositionCompManager.h"
#include "ModelCompManager.h"
#include "TextureCompManager.h"
#include "FreeCamableCompManager.h"
#include "OrientationCompManager.h"
#include "CameraMountCompManager.h"
#include "ControllableCompManager.h"
#include "GridCollisionCompManager.h"
#include "PickableCompManager.h"
#include "AABoundingBoxCompManager.h"
#include "HoverCamCompManager.h"
#include "StaminaCompManager.h"
#include "GuiPositionCompManager.h"
#include "ScaleCompManager.h"

#include "PrintNamesSystem.h"
#include "RenderSystem.h"
#include "FreeCamSystem.h"
#include "CamMountInfoSystem.h"
#include "GridMovementSystem.h"
#include "PickableSystem.h"
#include "HoverCamSystem.h"
#include "TurnBasedSystem.h"

class GamingState : public GameState
{
public:
	static GamingState * getInstance()
	{
		static GamingState instance; // Guaranteed to be destroyed.
											 // Instantiated on first use.
		return & instance;
	}
	GamingState(GamingState const&) = delete;
	void operator=(GamingState const&) = delete;

	void Init(GameEngine * game);
	void Cleanup(GameEngine * game);

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);
protected:
	GamingState() {}
private:
	PrintNamesSystem PrintNamesS = PrintNamesSystem();
	RenderSystem RenderS = RenderSystem();
	FreeCamSystem FreeCamS = FreeCamSystem();
	CamMountInfoSystem CamMountInfoS = CamMountInfoSystem();
	GridMovementSystem GridMovementS = GridMovementSystem();
	PickableSystem PickableS = PickableSystem();
	HoverCamSystem HoverCamS = HoverCamSystem();
	TurnBasedSystem TurnBasedS = TurnBasedSystem();

};