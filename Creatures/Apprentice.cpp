#include <Creatures/Apprentice.h>
#include <Skills/Heal.h>
#include <Skills/RangedAttack.h>

Apprentice::Apprentice() : Creature(50, 0, 10, 30, 25, "Apprentice", 'A')
{
	m_skills.push_back(std::make_shared<RangedAttack>(15));
	m_skills.push_back(std::make_shared<Heal>(30));
}

