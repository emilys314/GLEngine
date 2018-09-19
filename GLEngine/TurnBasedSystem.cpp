#include "TurnBasedSystem.h"


void TurnBasedSystem::update(int & keyPressed)
{
	if (endturn == true)
	{
		endturn = false;
	}

	if (keyPressed == 257)
	{
		endturn = true;
	}
}


bool & TurnBasedSystem::getEndTurn()
{
	return endturn;
}