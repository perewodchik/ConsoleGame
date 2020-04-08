#pragma once
#include <Skills/Skill.h>
#include <Creatures/Creature.h>

class Drain : public Skill
{
public:
	Drain(int damage);
	virtual void emit();
private:
	int m_damage;
};

