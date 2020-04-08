#pragma once
#include <Skills/Skill.h>
#include <Creatures/Creature.h>

class SplitArrows : public Skill
{
public:
	SplitArrows(int damage, int shots, int missChance);
	virtual void emit();
private:
	int m_damage;
	int m_shots;
	int m_missChance;
};

