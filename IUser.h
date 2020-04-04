#pragma once
#include <Position.h>
class IUser
{
	virtual Position getPosition() = 0;
	virtual int getTeam() = 0;
};

