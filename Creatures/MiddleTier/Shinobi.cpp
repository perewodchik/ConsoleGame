#include "Shinobi.h"

Shinobi::Shinobi() :
	Creature(70, 15, 45, 220, 120, "Shinobi")
{
	m_skills.push_back(std::make_shared<MeleeAttack>(40, 25));
	m_upgrades.push_back(CLASS::Naruto);
	m_evasion = 25;
}