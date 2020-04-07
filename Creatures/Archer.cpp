#include <Creatures/Archer.h>


Archer::Archer() : Creature(70, 15, 60, 100, 60, "Archer", 'A')
{
	m_skills.push_back(std::make_shared<RangedAttack>(30));
	m_canBeUpgraded = false;
}