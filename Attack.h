#pragma once
#include <Skill.h>
#include <Creature.h>

class Attack : public Skill
{
public:
	Attack();
	virtual void emit();
};

