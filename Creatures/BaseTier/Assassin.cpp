#include "Assassin.h"

Assassin::Assassin() : 
	Creature(45, 15, 35, 50, 40, "Assassin")
{
	m_skills.push_back(std::make_shared<MeleeAttack>(30,25));
	m_upgrades.push_back(CLASS::Archer);
	m_upgrades.push_back(CLASS::Shinobi);
}