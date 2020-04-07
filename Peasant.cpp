#include <Peasant.h>

Peasant::Peasant() : Creature(25, 0, 10, 30, 10, "Peasant", 'P')
{
	m_skills.push_back(std::make_shared<MeleeAttack>(25));
}