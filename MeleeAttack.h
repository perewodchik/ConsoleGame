#pragma once
#include <Skill.h>
#include <Creature.h>

class MeleeAttack : public Skill
{
public:
	MeleeAttack(int damage);
	virtual void emit();
private:
	int m_damage;
};

