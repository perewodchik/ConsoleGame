#include <Archer.h>


Archer::Archer() : Creature(50, 0, 70, 100, 40, "Archer", 'A')
{
	m_skills.push_back(std::make_shared<RangedAttack>(25));
	m_canBeUpgraded = false;
}