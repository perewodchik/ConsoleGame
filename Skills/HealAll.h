#pragma once

#include <Skills/Skill.h>

class HealAll : public Skill
{
public:
	HealAll(int heal);
	virtual void emit();
private:
	int m_heal;
};

