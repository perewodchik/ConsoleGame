#include "Apprentice.h"


Apprentice::Apprentice() : Creature(60, 0, 10, 30, 25, "Apprentice")
{
	m_skills.push_back(std::make_shared<RangedAttack>(15));
	m_skills.push_back(std::make_shared<Heal>(25));
	m_upgrades.push_back(CLASS::Priest);
	m_upgrades.push_back(CLASS::Warlock);
}

