#include <Creatures/HighTier/Anduin.h>

Anduin::Anduin() :
	Creature(80, 10, 40, 0, 200, "Anduin")
{
	m_skills.push_back(std::make_shared<Heal>(80));
	m_skills.push_back(std::make_shared<HealAll>(40));
	m_skills.push_back(std::make_shared<Resurrect>());
}
