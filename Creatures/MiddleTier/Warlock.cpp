#include "Warlock.h"

Warlock::Warlock() :
	Creature(55, 10, 30, 0, 100, "Warlock")
{
	m_skills.push_back(std::make_shared<Drain>(30));
}