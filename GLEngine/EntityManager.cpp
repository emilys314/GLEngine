#include "EntityManager.h"


GLuint EntityManager::createEntity()
{
	GLuint entityID;

	if ((!deletedIDs.empty()) && (deletedIDs.size() > 0))
	{
		entityID = deletedIDs[deletedIDs.size() - 1];//get last available id
		//deletedIDs.pop_back();//remove id from list of availables
		deletedIDs.erase(deletedIDs.size() - 1);
		//std::cout << "ID " << entityID << "\n";
		currentIDs[entityID] = entityID;
	}
	else
	{
		entityID = nextID;
		//currentIDs.push_back(entityID);
		currentIDs[entityID] = entityID;
		nextID++;
	}

	return entityID;
}

void EntityManager::destroyEntity(GLuint ID)
{
	currentIDs.erase(ID);
	//deletedIDs.push_back(ID);
	currentIDs[ID] = ID;
}

void EntityManager::cleanup()
{
	currentIDs.clear();
	deletedIDs.clear();
	GLuint nextID = 1;
}

void EntityManager::printIDs()
{
	for (int x = 0; x < currentIDs.size(); x++)
	{
		std::cout << currentIDs[x] << " ";
	}
	std::cout << "\n";
}