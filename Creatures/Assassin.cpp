#include <Creatures/Assassin.h>

Assassin::Assassin() : Creature(35, 15, 35, 50, 30, "Assassin", 'A')
{
	m_skills.push_back(std::make_shared<MeleeAttack>(25,25));
}