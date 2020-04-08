#include <Creatures/HighTier/Paladin.h>

Paladin::Paladin() :
	Creature(150, 30, 30, 0, 250, "Paladin")
{
	m_skills.push_back(std::make_shared<MeleeAttack>(25));
	m_skills.push_back(std::make_shared<Sacrifice>(20));
}