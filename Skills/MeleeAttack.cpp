#include <Skills/MeleeAttack.h>
#include <Creatures/Creature.h>

MeleeAttack::MeleeAttack(int damage) : Skill("Melee Attack")
{
	m_damage = damage;
	m_critChance = 0;
	m_spellName += " {" + std::to_string(m_damage) + "}";
}

MeleeAttack::MeleeAttack(int damage, int critChance) : Skill("Melee Attack")
{
	m_damage = damage;
	m_critChance = critChance;
	m_spellName += " {" + std::to_string(m_damage) + "}";
}

void MeleeAttack::emit()
{
	auto user = m_user.lock();
	auto enemyTarget = 
		m_targetHelper->getSingleEnemyTargetMelee(user->getPosition());

	system("cls");
	if (dice_rand() < enemyTarget->getEvasion())
	{
		std::cout << enemyTarget->getName()
			<< " has evaded the attack\n";
		return;
	}

	int dmgTaken;
	if (dice_rand() >= m_critChance)
	{
		dmgTaken = enemyTarget->takeDamage(m_damage);
		std::cout << enemyTarget->getName() 
			<< " was dealt "<< dmgTaken << " damage\n";
	}	
	else
	{
		dmgTaken = enemyTarget->takeDamage(m_damage + m_damage / 2);
		std::cout << "Crit!\n";
		std::cout << enemyTarget->getName()
			<< " was dealt " << dmgTaken << " damage\n";
	}
	
}