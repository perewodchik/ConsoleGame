#pragma once
#include <Misc/Position.h>
class IUser
{
public:
	virtual ~IUser() {};

	virtual Position getPosition() = 0;
	virtual int getTeam() = 0;
};

