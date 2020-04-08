#include <Creatures/HighTier/Hanzo.h>

Hanzo::Hanzo() :
	Creature(80, 20, 70, 0, 250, "Hanzo")
{
	m_skills.push_back(std::make_shared<RangedAttack>(40));
	m_skills.push_back(std::make_shared<SplitArrows>(30,4,33));
}
