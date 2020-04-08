#include "Peasant.h"

Peasant::Peasant() : Creature(55, 10, 15, 40, 20, "Peasant")
{
	m_skills.push_back(std::make_shared<MeleeAttack>(25));
	m_upgrades.push_back(CLASS::Knight);
	m_upgrades.push_back(CLASS::Spirit);
}