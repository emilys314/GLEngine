#pragma once

#include <iostream>

class TurnBasedSystem
{
public:
	void update(int & );
	bool & getEndTurn();
private:
	bool endturn;
};

