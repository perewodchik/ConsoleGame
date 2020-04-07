#include <Creatures/Peasant.h>

Peasant::Peasant() : Creature(45, 10, 15, 40, 20, "Peasant", 'P')
{
	m_skills.push_back(std::make_shared<MeleeAttack>(25));
}