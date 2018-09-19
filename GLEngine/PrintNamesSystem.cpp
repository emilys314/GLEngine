#include "PrintNamesSystem.h"



void PrintNamesSystem::Update(std::unordered_map<GLuint, std::string> & map)
{
	for (auto i : map)
	{
		std::cout << i.first << " " << i.second;
	}
}
