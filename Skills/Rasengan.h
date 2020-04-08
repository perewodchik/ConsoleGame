#pragma once
#include <Skills/Skill.h>
#include <Creatures/Creature.h>

class Rasengan : public Skill
{
public:
	Rasengan(int damage);
	virtual void emit();
private:
	int m_damage;
};

