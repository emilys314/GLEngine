#pragma once

#include <iostream>

#include "NameCompManager.h"

class PrintNamesSystem
{
public:
	void Update(std::unordered_map<GLuint, std::string> &);
};

