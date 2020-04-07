#pragma once
#include <Skills/Skill.h>

class Heal : public Skill
{
public:
	Heal(int heal);
	virtual void emit();
private:
	int m_heal;
};

