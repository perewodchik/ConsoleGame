#include "Spirit.h"

Spirit::Spirit() :
	Creature(60, 20, 20, 0, 0, "Spirit")
{
	m_skills.push_back(std::make_shared<MeleeAttack>(25));
}
