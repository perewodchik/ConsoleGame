#include "Archer.h"


Archer::Archer() 
	: Creature(90, 15, 60, 150, 80, "Archer")
{
	m_skills.push_back(std::make_shared<RangedAttack>(40));
	
	m_upgrades.push_back(CLASS::Hanzo);
}