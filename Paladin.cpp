#include <Creatures/HighTier/Paladin.h>

Paladin::Paladin() :
	Creature(120, 30, 30, 0, 250, "Paladin")
{
	m_skills.push_back(std::make_shared<MeleeAttack>(30));
	m_skills.push_back(std::make_shared<Sacrifice>(20));
}