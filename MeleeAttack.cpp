#include <MeleeAttack.h>
#include <Creature.h>

MeleeAttack::MeleeAttack(int damage) : Skill("Melee Attack")
{
	m_damage = damage;
}

void MeleeAttack::emit()
{
	auto user = m_user.lock();
	auto enemyTarget = 
		m_targetHelper->getSingleEnemyTargetMelee(user->getPosition());
	int dmgTaken =  enemyTarget->takeDamage(m_damage);
	std::cout << "enemy took" << dmgTaken << "damage\n";
}