#pragma once
#include <Skills/Skill.h>

class RangedAttack : public Skill
{
public:
	RangedAttack(int damage);
	virtual void emit();
private:
	int m_damage;
};

