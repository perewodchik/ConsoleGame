#include <Creature.h>
#include <Defend.h>

Creature::Creature(int hp, int armor, int initiative, int maxExp, int killExp, std::string name, char tag)
{
	m_canBeUpgraded = true;
	m_isDefending = false;
	m_health = hp;
	m_maxHealth = hp;
	m_armor = armor;
	m_maxExp = maxExp;
	m_killExp = killExp;
	m_initiative = initiative;
	m_name = name;
	m_tag = tag;
	m_team = -1;
	m_isDead = false;
	m_skills.push_back(std::make_unique<Defend>());
}

int Creature::receiveHeal(int value)
{
	int curHealth = m_health;
	m_health += value;
	if (m_health >= m_maxHealth)
		m_health = m_maxHealth;
	return m_health - curHealth;
}

int Creature::takeDamage(int value)
{
	int curHealth = m_health;
	if (m_isDefending)
		value /= 2;
	value *= 1 - m_armor / 100.0;
	m_health -= value;
	return curHealth - m_health;
}

void Creature::startDefending()
{
	m_isDefending = true;
}
