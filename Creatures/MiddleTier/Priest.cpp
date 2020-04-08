#include "Priest.h"

Priest::Priest()
	:Creature(80, 10, 35, 180, 70, "Priest")
{
	m_skills.push_back(std::make_shared<Heal>(50));
	m_skills.push_back(std::make_shared<HealAll>(30));

	m_upgrades.push_back(CLASS::Anduin);
}