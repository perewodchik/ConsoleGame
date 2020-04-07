#include <Skills/MeleeAttack.h>
#include <Creatures/Creature.h>

MeleeAttack::MeleeAttack(int damage) : Skill("Melee Attack")
{
	m_damage = damage;
	m_critChance = 0;
}

MeleeAttack::MeleeAttack(int damage, int critChance) : Skill("Melee Attack")
{
	m_damage = damage;
	m_critChance = critChance;
}

void MeleeAttack::emit()
{
	auto user = m_user.lock();

	std::mt19937::result_type seed = time(0);
	auto dice_rand = std::bind(std::uniform_int_distribution<int>(0, 100),
		std::mt19937(seed));

	auto enemyTarget = 
		m_targetHelper->getSingleEnemyTargetMelee(user->getPosition());

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