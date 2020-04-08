#pragma once
#include <Skills/Skill.h>
#include <Creatures/Creature.h>

class Resurrect : public Skill
{
public:
	Resurrect();
	virtual void emit();
private:
	bool m_used;
};

