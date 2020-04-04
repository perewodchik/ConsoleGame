#pragma once
#include "Skill.h"
class Attack : public Skill
{
public:
	virtual void emit(IUser* user);
};

