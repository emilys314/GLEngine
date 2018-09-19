#include "GridMovementSystem.h"



void GridMovementSystem::update(GLfloat & deltaTime, int & keyPressed, int & mouseButtonPressed, std::unordered_map<GLuint, GLuint> & controllable, std::unordered_map<GLuint, glm::vec3> & position, 
	std::unordered_map<GLuint, glm::vec3> & gridCollision,	glm::vec2 & gridPicked, GLuint & pickedEntityID, std::unordered_map<GLuint, staminadata> & staminamap, bool & endturn)
{
	if (endturn == true)//when the turn ends, refresh the stamina of each controllable unit
	{
		//for (auto i : controllable)
		for (auto i = controllable.begin(); i != controllable.end(); ++i)
		{
			//for (auto j : staminamap)
			for (auto j = staminamap.begin(); j != staminamap.end(); ++j)
			{
				if (i->first == j->first)
				{
					std::cout << j->second.currentstamina << " ";
					std::cout << j->second.basestamina << "\n";
					j->second.currentstamina = j->second.basestamina;
				}
			}
		}
	}


	//for (auto it = staminamap.begin(); it != staminamap.end(); ++it)
	//{
	//	std::cout << it->second.currentstamina << " ";
	//	it->second.currentstamina = 2;
	//	std::cout << it->second.currentstamina << "\n";
	//}
	
	bool shouldcreateMovementMap = false;
	bool shouldremoveMovementMap = false;

	if (controllable.size() > 0)//if there are controllable units to move
	{
		if (mouseButtonPressed == 0)//if unit is left clicked, make a map of were you can go
		{
			focusEntID = pickedEntityID;
			if (focusEntID > 0 && pickedEntityID > 0)
			{
				shouldcreateMovementMap = true;
				shouldremoveMovementMap = true;
			}
			else if(focusEntID > 0)
				shouldcreateMovementMap = true;
			else if(focusEntID == 0)
				shouldremoveMovementMap = true;


			//std::cout << "LEFTCLICK" << focus << "\n";
		}
		if (mouseButtonPressed == 1)//if a unit is selected and right clicked, move the unit there
		{
			if (focusEntID > 0)
			{
				bool colliding = false;
				for (auto i : gridCollision)
				{
					GLuint ID = i.first;
					if (gridCollision[ID].x == gridPicked.x && gridCollision[ID].z == gridPicked.y)
					{
						colliding = true;
						break;
					}
				}

				bool withinrange = false;//test to see if targeted grid is in range
				GLfloat distancefrombase = 0;
				for (auto t : movementmap)
				{
					if (t.tileposition.x == gridPicked.x && t.tileposition.z == gridPicked.y)
					{
						withinrange = true;

						std::cout << "dist " << t.distfrombase << "\n";

						distancefrombase = t.distfrombase;

						break;
					}
				}

				if (colliding == false && withinrange == true && staminamap[focusEntID].currentstamina > 0)//if there is no collision, do the movement
				{

					shouldremoveMovementMap = true;
					gridCollision[focusEntID].x = gridPicked.x;
					gridCollision[focusEntID].z = gridPicked.y;

					position[focusEntID].x = gridPicked.x;
					position[focusEntID].z = gridPicked.y;

					//std::cout << staminamap[focusEntID].currentstamina << " - " << distancefrombase << "\n";

					staminamap[focusEntID].currentstamina = staminamap[focusEntID].currentstamina - distancefrombase/2;

					focusEntID = 0;
				}
			}
		}

		if (shouldremoveMovementMap && movementmap.size() > 0)
		{
			for (tilestruct tile : movementmap)
			{
				PositionCompManager::getInstance().remove(tile.tileentityID);
				ModelCompManager::getInstance().remove(tile.tileentityID);
				TextureCompManager::getInstance().remove(tile.tileentityID);
				EntityManager::getInstance().destroyEntity(tile.tileentityID);
			}
			nexttileID = 1;
			movementmap.clear();
		}

		if (shouldcreateMovementMap && movementmap.size() == 0)
		{
			populatetilemap(position[focusEntID], staminamap[focusEntID].currentstamina, gridCollision);
		}
		
	}
}

GLfloat GridMovementSystem::distancetotilesquare(glm::vec3 focusposition, glm::vec2 gridtileposition)
{
	GLfloat distancetotravel = (std::sqrt((std::pow((focusposition.x - gridtileposition.x), 2)) + (std::pow((focusposition.z - gridtileposition.y), 2))));
	//std::cout << "distancetotravel = " << distancetotravel << "\n";
	distancetotravel = glm::round(distancetotravel);
	return distancetotravel;
}

void GridMovementSystem::populatetilemap(glm::vec3 baseposition, GLfloat size, std::unordered_map<GLuint, glm::vec3> & gridCollision)
{
	std::cout << "populatetilemap";
	std::cout << " size: " << size << " ";
	size = size * 2;
	std::cout << " size: " << size << "\n";
	tilestruct basetile;
	basetile.tileentityID = 0;
	basetile.tileposition = baseposition;
	basetile.distfrombase = 0;
	basetile.distfromparent = 0;
	basetile.isouterlayer = true;
	movementmap.push_back(basetile);

	GLuint movemapiterator = 0;
	GLuint movemapsize = movementmap.size();
	
	if (size > 0)
	{
		for (int y = 0; y < size / 2; y++)
		{
			for (int x = 0; x < movemapsize; x++)
			{
				//tilestruct tile = movementmap[x];

			//std::cout << "movemapiterator " << movemapiterator << "\n";

				tilestruct tile = movementmap[x];
				if (tile.isouterlayer == true)
				{
					//tilestruct tile = movementmap[movemapiterator];
					//try to create upper tile
					trytocreatenewperptile(tile.tileposition, glm::vec3(0, 0, -2), x, size, gridCollision);
					//try to create right tile
					trytocreatenewperptile(tile.tileposition, glm::vec3(2, 0, 0), x, size, gridCollision);
					//try to create lower tile
					trytocreatenewperptile(tile.tileposition, glm::vec3(0, 0, 2), x, size, gridCollision);
					//try to create lelft tile
					trytocreatenewperptile(tile.tileposition, glm::vec3(-2, 0, 0), x, size, gridCollision);
				}
			}
			for (int x = 0; x < movemapsize; x++)
			{
				tilestruct tile = movementmap[x];
				if (tile.isouterlayer == true)
				{
					//tilestruct tile = movementmap[movemapiterator];
					//try to create upper right tile
					trytocreatenewdiagtile(tile.tileposition, glm::vec3(2, 0, -2), x, size, gridCollision);
					//try to create lower right tile
					trytocreatenewdiagtile(tile.tileposition, glm::vec3(2, 0, 2), x, size, gridCollision);
					//try to create lower left tile
					trytocreatenewdiagtile(tile.tileposition, glm::vec3(-2, 0, 2), x, size, gridCollision);
					//try to create upper lelft tile
					trytocreatenewdiagtile(tile.tileposition, glm::vec3(-2, 0, -2), x, size, gridCollision);
				}
			}
			for (int x = 0; x < movemapsize; x++)
			{
				tilestruct tile = movementmap[x];
				if (tile.isouterlayer == true)
				{
					tile.isouterlayer = false;
				}
			}
			movemapiterator++;
			movemapsize = movementmap.size();
		}
	}
	//std::cout << "MapSize" << movemapsize << "\n";
}

void GridMovementSystem::trytocreatenewperptile(glm::vec3 oldtileposition, glm::vec3 offsetfornewtile, GLuint parenttileID, GLuint size, std::unordered_map<GLuint, glm::vec3> & gridCollision)
{
	tilestruct parenttile = movementmap[parenttileID];

	//test if the new tile is in range
	if (std::round(parenttile.distfrombase + 2) <= size)
	{
		bool isthereatilealready = false;
		for (auto t : movementmap)//test if there are already tiles there
		{
			if (t.tileposition == oldtileposition+offsetfornewtile)
			{
				isthereatilealready = true;
				break;
			}
		}
		bool iscolliding = false;
		if (isthereatilealready == false)
			for (auto collisionbox : gridCollision)
			{
				if (((oldtileposition.z + offsetfornewtile.z == collisionbox.second.z) && (oldtileposition.x + offsetfornewtile.x == collisionbox.second.x))
					|| ((oldtileposition.z + offsetfornewtile.z/2 == collisionbox.second.z) && (oldtileposition.x + offsetfornewtile.x/2 == collisionbox.second.x)))
				{
					iscolliding = true;
					break;
				}
			}

		if (iscolliding == false && isthereatilealready == false)
		{
			tilestruct newtile;
			newtile.tileposition = glm::vec3(oldtileposition + offsetfornewtile);
			newtile.parentposition = parenttile.tileposition;
			newtile.distfromparent = distancetotilesquare(newtile.tileposition, glm::vec2(parenttile.tileposition.x, parenttile.tileposition.z));
			newtile.distfrombase = parenttile.distfrombase + newtile.distfromparent;
			newtile.tileentityID = nexttileID;
			//std::cout << "CREATE NEW TILE dist from base: " << newtile.distfrombase << " \n";

			newtile.tileentityID = EntityManager::getInstance().createEntity();
			PositionCompManager::getInstance().set(newtile.tileentityID, glm::vec3(newtile.tileposition.x, 0.001f, newtile.tileposition.z));
			ModelCompManager::getInstance().set(newtile.tileentityID, tileplane.getVAOid(), tileplane.getVertCount());
			TextureCompManager::getInstance().set(newtile.tileentityID, highlighted);
			newtile.isouterlayer = true;
			movementmap.push_back(newtile);
			nexttileID++;
		}
	}
}

void GridMovementSystem::trytocreatenewdiagtile(glm::vec3 oldtileposition, glm::vec3 offsetfornewtile, GLuint parenttileID, GLuint size, std::unordered_map<GLuint, glm::vec3> & gridCollision)
{
	tilestruct parenttile = movementmap[parenttileID];

	//test the upper tile ^^
	if (std::round(parenttile.distfrombase + 2.82) <= size)
	{
		bool isthereatilealready = false;
		for (auto t : movementmap)
		{
			if (t.tileposition == oldtileposition + offsetfornewtile)
			{
				isthereatilealready = true;
				break;
			}
		}
		bool iscolliding = false;
		if (isthereatilealready == false)
			for (auto collisionbox : gridCollision)
			{
				if (((oldtileposition.z + offsetfornewtile.z == collisionbox.second.z) && (oldtileposition.x + offsetfornewtile.x == collisionbox.second.x))
					|| ((oldtileposition.z + offsetfornewtile.z / 2 == collisionbox.second.z) && (oldtileposition.x + offsetfornewtile.x / 2 == collisionbox.second.x)))
				{
					iscolliding = true;
					break;
				}
				if (((oldtileposition.z == collisionbox.second.z) && (oldtileposition.x + offsetfornewtile.x == collisionbox.second.x))
					|| ((oldtileposition.z == collisionbox.second.z) && (oldtileposition.x + offsetfornewtile.x / 2 == collisionbox.second.x)))
				{
					iscolliding = true;
					break;
				}
				if (((oldtileposition.z + offsetfornewtile.z == collisionbox.second.z) && (oldtileposition.x == collisionbox.second.x))
					|| ((oldtileposition.z + offsetfornewtile.z / 2 == collisionbox.second.z) && (oldtileposition.x == collisionbox.second.x)))
				{
					iscolliding = true;
					break;
				}
			}

		if (iscolliding == false && isthereatilealready == false)
		{
			tilestruct newtile;
			newtile.tileentityID = nexttileID;
			//std::cout << "CREATE NEW TILE: " << nexttileID << " \n";
			newtile.tileposition = glm::vec3(oldtileposition + offsetfornewtile);
			newtile.parentposition = parenttile.tileposition;
			newtile.distfromparent = 2.82;
			//std::cout << "distfromparent " << newtile.distfromparent << " \n";
			newtile.distfrombase = parenttile.distfrombase + 2.82;
			//std::cout << "distfrombase " << newtile.distfrombase << " \n";

			newtile.tileentityID = EntityManager::getInstance().createEntity();
			PositionCompManager::getInstance().set(newtile.tileentityID, glm::vec3(newtile.tileposition.x, 0.001f, newtile.tileposition.z));
			ModelCompManager::getInstance().set(newtile.tileentityID, tileplane.getVAOid(), tileplane.getVertCount());
			TextureCompManager::getInstance().set(newtile.tileentityID, highlighted);
			newtile.isouterlayer = true;
			movementmap.push_back(newtile);
			nexttileID++;
		}
	}
}