#include <Creatures/HighTier/Naruto.h>

Naruto::Naruto()
	:Creature(100, 20, 50, 0, 250, "Naruto")
{
	m_skills.push_back(std::make_shared<MeleeAttack>(60,33));
	m_skills.push_back(std::make_shared<Rasengan>(50));

	m_evasion = 33;
}