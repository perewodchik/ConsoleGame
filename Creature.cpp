#include <Creature.h>
#include <Attack.h>
#include <Defend.h>

Creature::Creature(int hp, int armor, int initiative, int maxExp, int killExp, std::string name, char tag)
{
	m_isDefending = false;
	m_curExp = 0;
	m_health = hp;
	m_maxHealth = hp;
	m_armor = armor;
	m_maxExp = maxExp;
	m_killExp = killExp;
	m_initiative = initiative;
	m_name = name;
	m_tag = tag;
	m_team = -1;
	m_skills.push_back(std::make_unique<Attack>());
	m_skills.push_back(std::make_unique<Defend>());
}

void Creature::receiveHeal(int value)
{
	m_health += value;
	if (m_health >= m_maxHealth)
		m_health = m_maxHealth;
}

void Creature::takeDamage(int value)
{
	if (m_isDefending)
		value /= 2;
	value *= 1 - m_armor / 100.0;
	m_health -= value;
}

void Creature::addExperience(int value)
{
	m_curExp += value;
	if (m_curExp > m_maxExp)
	{
		m_curExp = m_maxExp;
	}
}

void Creature::setTeam(int team)
{
	m_team = team;
}

void Creature::setPosition(Position pos)
{
	m_position = pos;
}

void Creature::startDefending()
{
	m_isDefending = true;
}