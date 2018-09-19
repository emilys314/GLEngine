#include "StaminaCompManager.h"


void StaminaCompManager::set(GLuint ID, GLfloat basestamina, GLfloat currentstamina)
{
	staminadata newstruct;
	newstruct.basestamina = basestamina;
	newstruct.currentstamina = currentstamina;
	map[ID] = newstruct;
}

void StaminaCompManager::remove(GLuint ID)
{
	map.erase(ID);
}

void StaminaCompManager::cleanup()
{
	map.clear();
}

std::unordered_map<GLuint, staminadata> & StaminaCompManager::getMap()
{
	return map;
}
