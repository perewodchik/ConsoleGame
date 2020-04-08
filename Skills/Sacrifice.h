#pragma once
#include <Skills/Skill.h>
#include <Creatures/Creature.h>

class Sacrifice : public Skill
{
public:
	Sacrifice(int armor);
	virtual void emit();
private:
	int m_armor;
};

