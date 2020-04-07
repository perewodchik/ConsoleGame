#pragma once
#include <Skills/Skill.h>
#include <Creatures/Creature.h>
#include <random>
#include <ctime>
#include <functional>

class MeleeAttack : public Skill
{
public:
	MeleeAttack(int damage);
	MeleeAttack(int damage, int critChance);
	virtual void emit();
private:
	int m_damage;
	int m_critChance;
};

