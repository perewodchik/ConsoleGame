#include <Attack.h>
#include <Creature.h>

Attack::Attack() : Skill("Attack")
{
}

void Attack::emit()
{
	auto user = m_user.lock();
	auto enemyTarget = 
		m_targetHelper->getSingleEnemyTarget(user->getPosition());
	enemyTarget->takeDamage(25);
	std::cout << "enemy took 25 damage\n";
}