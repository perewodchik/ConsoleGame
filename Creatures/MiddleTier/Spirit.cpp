#include "Spirit.h"

Spirit::Spirit() :
	Creature(70, 20, 30, 0, 0, "Spirit")
{
	m_skills.push_back(std::make_shared<MeleeAttack>(30));
}
