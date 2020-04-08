#include "Knight.h"

Knight::Knight() :
	Creature(120, 40, 25, 200, 100, "Knight")
{
	m_skills.push_back(std::make_shared<MeleeAttack>(15));
	m_skills.push_back(std::make_shared<GiveDefend>());

	m_upgrades.push_back(CLASS::Paladin);
}